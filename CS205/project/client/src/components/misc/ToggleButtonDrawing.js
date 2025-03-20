import React, { useState, useRef, useEffect } from "react";
import Grid from '@mui/material/Grid';
import Box from "@mui/material/Box";
import Button from "@mui/material/Button";
import CanvasDraw from "react-canvas-draw";
import { TextBox } from "../styles/TextStyles";
import { Typography, useThemeProps } from "@mui/material";
import ImagePrediction from "./ImagePrediction";

var RandChar = () => {
    let result = ''; 
    const characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
    result += characters.charAt(Math.floor(Math.random() * characters.length));
    return result; 
};

const ToggleButtonDrawing = (props) => {
  
    const [show, setShow] = useState(false);
    const canvasRef = useRef(null);
    const [drawing, setDrawing] = React.useState();
    const [ticking, setTicking] = useState(false);

    // This is for the time interval
    // const [ticking, setTicking] = useState(false)
    // const [count, setCount] = useState(0)

    // useEffect(() => {
    //     const timer = setTimeout( () => ticking && setCount(count + 1), 1000)
    //     return () => clearTimeout(timer)
    // }, [count, ticking]);

    var randChar

    const ExportDrawing = () => {

        var base64 = canvasRef.current.canvasContainer.childNodes[1].toDataURL("image/png");
        setDrawing(base64); // just clear it for now
        
        console.log(randChar);
    
        // downloading
        // base64 = base64.replace("image/png", "image/octet-stream"); 
        // window.location.href=base64; 
        // var link = document.getElementById('download_image');
        // console.log(base64);

        let long = 0;
        let latt = 0;
    
        if ("geolocation" in navigator) {
          navigator.geolocation.getCurrentPosition(function(position) {
            long = position.coords.longitude;
            latt = position.coords.latitude;
          });
        }
        else {
          long = -9999.999;
          latt = -9999.999;
        }
        
        const postBody = JSON.stringify({
            label: randChar, // TODO: insert variable name
            data: base64, // trying base64 but I fear it will not work
            longitude: long,
            latitude: latt
        });
    
        const options = {
          method: "POST",
          headers: {
            'Content-Type': 'application/json',
            "Accept": "application/json",
          },
          body: postBody
        };
    
        fetch("http://localhost:8000/api/image/", options)
        .then(response => response.json());
    };

    return (
        <Grid
          container
          spacing={4}
          columns={16}>
          <Grid item xs={16}>
            {!show ?
            <Button
              style={{width: "25%", height: "150%", fontSize:25}}
              variant="contained"
                onClick={() => {
                    setShow(true);
                    setTicking(true);
                    props.setShowParentInstructions(false);
                }
              }
            >
              Start
            </Button>
            : <Box></Box>
            }
          </Grid>
          <Grid item xs={8}>
          {show ?
              <Box>
                <Typography variant="h4">
                  Draw the character "{ randChar = RandChar() }"
                </Typography>
                <CanvasDraw
                    ref={ canvasRef }
                    style={ {
                      marginRight: "auto",
                      marginLeft: "auto",
                      border: '5px solid black',
                      background: "black"
                      } }
                    
                    brushRadius={50}
                    brushColor="white"
                    canvasWidth={800}
                    canvasHeight={800}

                    onClick={ () => {
                        console.log("clicking canvas");
                    }}
                />
              </Box>
              
          : <Box></Box>
          }
          </Grid>
          <Grid item xs={8}>
            <Grid
              container
              spacing={2}
              columns={16}>
              <Grid item xs={16}>
                {
                    show ?
                    <>
                      <Box>
                      <Typography variant="h4">
                          Predictions (Most to Least Likely)
                      </Typography>
                      </Box>
                      <ImagePrediction canvas={canvasRef}/>
                    </>
                    : <Box></Box>
                }
              </Grid>
              <Grid item xs={16} >
              {show ?
                
                <Box >
                  <Button
                    style={{width: "25%", height: "150%", fontSize:25}}
                    variant="contained" 
                    onClick={() => {
                      canvasRef.current.undo();
                    }}>Undo
                  </Button>
                  <Button
                    style={{width: "25%", height: "150%", fontSize:25}}
                    variant="contained"
                    onClick={() => {
                      canvasRef.current.clear();
                  }}>Clear</Button>
                  <Button
                    style={{width: "25%", height: "150%", fontSize:25}}
                    variant="contained"
                    onClick={ () => {
                      ExportDrawing();
                      canvasRef.current.clear();
                    }}
                    >Next</Button> 
                  {/* <Box>
                  <a id = "download_image"> <img src={drawing}/> </a>
                  </Box> */}
                  
                </Box>
                : <Box></Box>}
              </Grid>
            </Grid>
          </Grid>
        </Grid>
    )
  };

export default ToggleButtonDrawing;