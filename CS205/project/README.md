# CS205-Project

## Set-Up Steps: 
1. Clone the Repository
2. Set up React Frontend
3. Set up Django Backend 
4. Notes 

## Set up React Frontend 
* `install nvm` or `wget -qO- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.1/install.sh | bash`
* restart bash profile
* `source ~/.bash_profile` 
* `nvm install 18.13.0` 
  * get node version 18.13.0
* `nvm install-latest-npm` 
  * get npm version 9.4.0 or higher 
* go to the client folder
* `npm install react-scripts@latest`

## Set up Django Backend 
Works in both python 3.8 and 3.10
Install the following libraries. We used pip. 
```
pip install django django-cors-headers
pip install djangorestframework
pip install tensorflow keras 
pip install pillow
``` 
* for other ways to install django rest framework you can check the website: https://www.django-rest-framework.org/


To start client: 
```
npm install 
npm start
```
opens by default on port 3000

To start the django backend: 
```
python manage.py runserver 
```
opens by default on port 8000

**Notes:** 
The model is already saved and will be loaded automatically, but if you want to add your own model you will need to download the dataset on your own local machine and install the necessary libraries. 
You can recreate our steps using model/create_model.py. We save our model to `model/saved_models`.
You will have to create your own `.env` file in the repo that contain the following paths: DATA_PATH, TRAIN_X_FILE, TRAIN_Y_FILE, TEST_X_FILE, TEST_Y_FILE, and MAP_FILE. 
We use the emnist-bymerge split from the EMNIST dataset which has 814,255 characters and 47 classes. 
For more information about the EMNIST dataset you can visit: https://www.nist.gov/itl/products-and-services/emnist-dataset
