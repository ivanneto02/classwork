import React, {useState} from "react";

import Button from "@mui/material/Button"
import Box from "@mui/material/Box"
import { Typography } from "@mui/material";

// Credit: https://stackoverflow.com/questions/43692479/how-to-upload-an-image-in-react-js
// drag drop file component
function DragDropFile(props) {
    const [selectedImage, setSelectedImage] = useState(null);
    const [base64, setBase64] = useState(null);

    return (
      <form id="form-file-upload">
        <input
          type="file"
          id="input-file-upload"
          multiple={false}
          onChange={
            (event) => {
              props.setSelectedImage(event.target.files[0]);
              setSelectedImage(event.target.files[0]);
            }
          }
        />
        <label id="label-file-upload" htmlFor="input-file-upload">
          <div>
            <p>Drag and drop your file here or</p>

          </div>
            <Box
              style={{
                marginLeft: "auto",
                marginRight: "auto",
                border: '5px solid black',
              }}
              height="100%"
              width="50%"
              alignItems={"center"}
              alignContent={"center"}
              justifyContent={"center"}
            >
                {selectedImage ? 
                <div>
                    <img
                      alt="No current image"
                      width={"100%"}
                      src= { URL.createObjectURL(selectedImage) }
                    />
                  <br />
                </div>
                : <Typography
                    variant="h2">No image</Typography>
                }
            </Box>
        </label>
      </form>
    );
  };

export default DragDropFile;