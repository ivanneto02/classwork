import React from "react";
import Grid from '@mui/material/Grid';
import {TextBox, Title} from "../styles/TextStyles";
import Typography from "@mui/material/Typography";

function About() {
  return (
      <Grid container spacing={2} columns={3}>
      <Grid item xs={3}>
        <Title component="h1">
          About
        </Title>
        
      </Grid>
      <Grid item xs={3}>
      <TextBox>
        <Typography variant="h5">
        The project focuses on a web application where (1) users can contribute their data to a repository of images, and (2) users can detect their own handwriting by uploading or taking their own images.
	      
        <br/><br/>

        Aspect (1) focuses on the backend side of the application, where the data is stored. The application prompts users to draw a specific alphanumeric character (i.e. “a”, “b”, “c”), and the user is given a drawing canvas to hand write the letter. After handwriting the letter, the user is shown whether the internal Machine Learning model recognized their character. If successful, the application shows the user, and the user’s image is uploaded to our backend. If the model is unsuccessful, the application shows the user, and the user’s image is uploaded as its intended label to the backend.
	      
        <br/><br/>

        The second aspect (2) focuses on the user’s experience of the application. Users need something tangible to connect with our application. By uploading their own images and having the application recognize the digits they have written, users have a use for the application besides data collection.
        
        </Typography>
      </TextBox>
      </Grid>
      <Grid item xs={3}>
        <Title component="h2">
          Background & Motivation
        </Title>
        <TextBox>
        <Typography variant="h5">
        In the Machine Learning and Data Mining spheres, lack of data availability is a real problem that affects both (1) researchers and (2) users. Computer Science researchers need data to be available to build well-performing and robust Machine Learning models that accommodate user needs in performing daily tasks.
        
        <br/><br/>

        Our project tackles the ever-growing need for data availability, specifically for hand-drawn alphanumeric character images. By using our application, users are able to contribute to a repository of hand-drawn letters and numbers. This data collection is coupled with an online-learning scheme to upgrade the Machine Learning model utilized for users to see what their work is amounting to.
	      
        <br/><br/>

        On the user side, users would be able to take a picture of their own handwriting and see the results of this model. By contributing to our operation, users are actively improving the model and getting better predictions as a result.
        </Typography>
        </TextBox>
      </Grid>
      
    </Grid>
  );
}
  
export default About;