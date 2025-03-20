from django.db import models

class Image(models.Model):
    '''
        Image model. We store the following attributes:
            - img_id
            - label
            - timestamp
            - data
            - longitude
            - latitude
    '''

    img_id = models.AutoField(primary_key=True)
    label = models.CharField(max_length=10, default="none") # holds the label of the image
    timestamp = models.TimeField(auto_now=True)
    data = models.ImageField()

    # Credit to "shacker" and "C.K." in (https://stackoverflow.com/questions/30706799/which-model-field-to-use-in-django-to-store-longitude-and-latitude-values)
    # for longitude and latitude parameters
    longitude = models.DecimalField(max_digits=22, decimal_places=16, blank=True, null=True)
    latitude  = models.DecimalField(max_digits=22, decimal_places=16, blank=True, null=True)