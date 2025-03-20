import numpy as np
import gzip

def load_imgs(dpath, length=731668): # 731,668 samples in the training set
    '''
    In charge of loading the images of the EMNIST dataset. These images
    are stored in idx3-ubyte.gz files, which need a special routine to
    open and store. These images must be (1) flipped horizontally, and
    (2) rotated clockwise 3 times, to be properly fed to a Machine
    Learning algorithm or other endeavors.
    
    Parameters:
        dpath - data path of the image file
        len   - how many images we want to load
    '''
    
    # Create binary file read object
    f_data = open(dpath, "rb")

    # Size of the NxN image, and how many images
    image_size = 28
    num_images = length

    # Skip useless data
    f_data.read(16)

    # Read the file data into buffer
    buf = f_data.read(image_size * image_size * num_images)
    data = np.frombuffer(buf, dtype=np.uint8).astype(np.float32)

    # Reshape, flip horizontally, rotate clockwise 3 times
    data = data.reshape(num_images, image_size, image_size)
    data = np.flip(data, axis=1)
    data = np.array([np.rot90(img, 3) for img in data])
    return data

def load_labs(dpath, length=731668): # 731,668 samples in the training set
    '''
    In charge of loading the labels of the EMNIST dataset. These labels
    are the EMNIST standard for labeling their images
    
    Parameters:
        dpath - data path of the label file
        len   - how many labels we want to load
    '''
    # Create binary file read object
    f = open(dpath,'rb')

    # Skip useless data
    f.read(8)

    # Read in the labels
    labels = []
    for i in range(0, length):   
        buf = f.read(1)
        label = np.frombuffer(buf, dtype=np.uint8).astype(np.int64)
        labels.append(label)
    return np.array(labels)

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

if __name__ == "__main__":
    print('''You are currently attempting to run a utility file. Stop.''')