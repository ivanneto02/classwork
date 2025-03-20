import React from "react";
import Grid from '@mui/material/Grid';
import {TextBox, Title} from "../styles/TextStyles";
import Button from "@mui/material/Button";
import Box from "@mui/material/Box";

import { HeroBox } from "../styles/HeroBox";
import { requirePropFactory, Typography } from "@mui/material";
import { Link } from "react-router-dom";

function Home() {
  
  return (
      <Grid container spacing={2} columns={2} >
      <Grid item xs={2}>
        
        <HeroBox>
        <h1>
          AlphaNumeric Detector 
        </h1>
          
        </HeroBox>
      </Grid>
      <Grid item xs={1}>
        <Box textAlign="center">
        <Link to="/draw" style={{ textDecoration: 'none', color: 'DodgerBlue' }} > 
          <Button
            style={{width: "50%", height: "150%", fontSize:25}}
            variant="outlined">
          Drawing
          </Button>
        </Link>
        </Box>
      </Grid>
      <Grid item xs={1}>
        <Box textAlign="center">
        <Link to="/detect" style={{ textDecoration: 'none', color: 'DodgerBlue' }}>
          <Button
            style={{width: "50%", height: "150%", fontSize:25}}
            variant="outlined">
           Detect
          </Button>
          </Link>
        </Box>
      </Grid>
      <Grid item xs={2}>
        <TextBox
          style={
            {
              marginLeft:"5%",
              marginRight:"5%"
            }
          }
        >
          <Typography variant="h5">
            Data scarcity is very real for certain applications. For instance, the MNIST dataset only has around 60 thousand samples to work with.
            And while the EMNIST dataset has significantly more, there remains a need to gather character image data. This project proposes a fun
            way to gather this data in an crowd sourcing manner. The more users utilize this website for its intended purpose, the more good quality
            data we will have to carry out useful tasks.

            <br/><br/>

            The <b>DRAWING</b> mode focuses on the data collection aspect of our project, whereas the <b>DETECT</b> mode focuses on the fun user application.
            Specifically, users upload an image. Then, with the help of our internal Machine Learning model, we detect characters within their image to the
            best of our ability.

            <br /> <br />

            Click on <b>"DRAWING"</b> or <b>"DETECT"</b> to continue.

          </Typography>
        </TextBox>
      </Grid>
      <Grid item xs={2}>
        <Title component="h1">
          Gallery
        </Title>
        <Box>
          <Typography
            align="left"
            marginLeft="5%"
            variant="h5">
            Below are some samples of images taken from the emnist dataset. Eventually, when more user data becomes available,
            we will be able to see drawings from other users:
          </Typography>
          <TextBox
            style={
              {
                marginLeft:"5%",
                marginRight:"5%",
                border: '2px solid black',
                marginTop: "1%"
              }
            }
          >
            <Grid
              container
              style={{
                justifyContent: "center",
                alignContent: "center",
                marginLeft: "auto",
                marginRight: "auto",
              }}
              p={4} 
              spacing={{ xs: 1, md: 1 }}
              columns={{ xs: 4, sm: 12, md: 16 }}>

                {Array.from(Array(20)).map((_, index) => (
                  <Grid item xs={2} sm={4} md={4} key={index}>
                    <Box>
                      <img
                        src={require(`./../../galleryimages/image${index}.png`)}
                        alt={`image${index}`}
                        loading="lazy"
                        width="250" 
                        height="200"
                      />
                    </Box>
                  </Grid>
                ))}
            </Grid>
          </TextBox>

        </Box>
      </Grid>
    </Grid>
  );
}
  
export default Home;