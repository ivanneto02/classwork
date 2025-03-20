from django.shortcuts import render

from .apps import EmnistdetectoConfig

# Create your views here.
from django.http import HttpResponse, JsonResponse
from django.shortcuts import get_object_or_404
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
import matplotlib.pyplot as plt

from PIL import Image, ImageOps
import base64
from io import BytesIO
import numpy as np

def load_map(dpath):
    '''
    In charge of loading the mappings between what EMNIST names each
    label, and the actual ASCII character that said label belongs to.
    
    Parameters:
        dpath - data path of the mapping file
    '''

    # Create dictionary and populate it from the mapping file
    mapping_dictionary = {}
    with open(dpath) as dict_file:
        for line in dict_file:
            (key, val) = line.split()
            mapping_dictionary[int(key)] = chr(int(val))
        return mapping_dictionary

def base64ToPil(data):
    '''Converts base64 to Pillow image
    
        Credit: https://stackoverflow.com/questions/31826335/how-to-convert-pil-image-image-object-to-base64-string
    '''
    data = data.replace(" ", "+")
    decoded = base64.b64decode(data.split(",")[1])
    buffered = BytesIO(decoded)
    img = Image.open(buffered)
    img = ImageOps.grayscale(img)
    return img

# Credit to https://medium.com/saarthi-ai/deploying-a-machine-learning-model-using-django-part-1-6c7de05c8d7
class call_model(APIView):

    # Define get request
    def get(self, req):
        
        # load mapping from index to direct label
        mapping_dict = load_map("emnistmodel/model/mappings.txt")

        # get the data of the image (base64, will have to convert later)
        data = req.GET.get("data")

        # Convert base64 image to Pillow Image
        pil_img = base64ToPil(data)

        # Downsample image
        down_img = np.array(pil_img.resize((28, 28), Image.BOX))

        # plt.imshow(down_img)
        # plt.savefig("digit_imgs/test.png")

        # print(down_img)
        # img = Image.fromarray(down_img)
        # img.save("digit_imgs/test.png")

        down_img = np.reshape(down_img, (1, 28, 28)).astype("float32")
        down_img /= 255

        # print("testing, image\n\n\n")
        # print(down_img)

        prediction = EmnistdetectoConfig.PRETRAINED_MODEL.predict(down_img).flatten()

        # print(prediction)

        sorted_index = prediction.argsort()

        # print(sorted_index)

        sorted_pred  = np.flip(prediction[sorted_index]).tolist()
        sorted_index = np.flip(sorted_index).tolist()
        labels = [ mapping_dict[x] for x in sorted_index ]

        response = {
            'prediction' : sorted_pred[:10],
            'indexes' : sorted_index[:10],
            'labels' : labels[:10],
        }

        return JsonResponse(response)