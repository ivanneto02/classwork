import React, {useState} from "react";
import Grid from '@mui/material/Grid';
import {TextBox, Title} from "../styles/TextStyles";
import Button from "@mui/material/Button";
import Box from "@mui/material/Box";
import { Typography } from "@mui/material";
import {DragDropFile} from "../misc/DragAndDrop";
import ToggleButtonDetect from "../misc/ToggleButtonDetect";

function Detecting() {
  const [show, setShow] = useState(true);

  return (
    <Grid container spacing={2} columns={3}>
      <Grid item xs={3}>
        <Title component="h1">
          Detection
        </Title>
      </Grid>
      <Grid item xs={3}>
        { show ?
          <TextBox>
                <Typography>
                  Detect your own drawings! This mode is for your own enjoyment, we do not collect any of your drawing data.
                </Typography>

                <br></br>

                <Typography>
                  Upon starting, you will be asked to upload an image containing alphanumeric characters.
                  You may choose anything from handdrawn digits, letters, to a typed equivalent. <b>Please ensure your image is in PNG format.</b>
                </Typography>

                <br></br>

                <Typography>Press <b>"Start"</b> to begin.</Typography>
              </TextBox>
              : <Box></Box>
          }
      </Grid>
      <Grid item xs={3}>
        <Box textAlign="center">
          <ToggleButtonDetect setShow={setShow}/>
        </Box>
      </Grid>
    </Grid>
  );
}
  
export default Detecting;