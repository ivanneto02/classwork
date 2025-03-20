from rest_framework import serializers
from .models import Image
import PIL.Image
import base64
from django.core.files.base import ContentFile
from django.core.files.uploadedfile import InMemoryUploadedFile
from io import BytesIO

# credit to Access to fetch at 'http://localhost:8000/api/image/' from origin 'http://localhost:3000' has been blocked by CORS policy
class Base64ImageField(serializers.ImageField):
    """
    A Django REST framework field for handling image-uploads through raw post data.
    It expects the incoming post data to contain the base64 encoded image data under the field name `image`.
    """
    def to_internal_value(self, data):
        
        # Check if the base64 string is in the "data:" format
        # If it is, extract the image data and decode it
        format, imgstr = data.split(';base64,')
        ext = "png"
        data = ContentFile(base64.b64decode(imgstr), name=f'digit_imgs/img.{ext}')
        # Use PIL to create an Image object from the decoded image data
        # print("raw string\n\n", imgstr)
        # print("testing got here1\n")
        # img = PIL.Image.open(data)
        # # Convert the image object to an appropriate format
        # print("testing got here2\n")
        # output = BytesIO()
        # print("testing got here3\n")
        # img.save(output, format='png', quality=80)
        # print("testing got here4\n")
        # output.seek(0)
        # print("testing got here5\n")

        # Call the parent class's `to_internal_value` method to create the `ImageField` instance
        data = super().to_internal_value(data)

        # print(data)

        return data


class ImageSerializer(serializers.ModelSerializer):

    data = Base64ImageField()

    class Meta:
        model = Image
        fields = (
            'img_id',
            'label',
            'timestamp',
            'data',
            'longitude',
            'latitude'
        )