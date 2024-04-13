# PixelGAN - CycleGAN for pixel art generation

## Overview

This repository contains the implementation of CycleGAN for generating pixel art from scenery images and vice versa. CycleGAN is a type of Generative Adversarial Network (GAN) that learns to map images from one domain to another without the need for paired data.

## Requirements

- Python (>= 3.6)
- PyTorch (>= 1.7)
- TorchVision (>= 0.8)
- Albumentations (>= 1.0)

## Installation

1. Clone the repository:

```bash
git clone https://github.com/Hexanol777/PixelGAN.git
cd PixelGAN
```
2.Install the required packages:
```bash
pip install -r requirements.txt
```

## Usage
1. Preprocess the dataset:
- Place your scenery images in the `dataset/train/scenery` directory.
- Place your pixel art images in the `dataset/train/pixel` directory.
- Place validation images in `dataset/val` similarly.
2. Train the model:
- this can be done by running the cells inside `PixelGAN_Training.ipynb`

## Datasets

- **Domain A (Scenery Images)**: i used the images on Danbooru for this case
- **Domain B (Pixel Art Images)**: [Domain B](https://www.kaggle.com/datasets/artvandaley/curated-pixel-art-512x512)

## Results

Result 1:
![Result1](https://github.com/Hexanol777/PixelGAN/blob/main/results/Figure_1.png)

Result 2:
![Result2](https://github.com/Hexanol777/PixelGAN/blob/main/results/Figure_2.png)

Result 3:
![Result3](https://github.com/Hexanol777/PixelGAN/blob/main/results/Figure_3.png)

Result 4:
![Result3](https://github.com/Hexanol777/PixelGAN/blob/main/results/Figure_4.png)


## Model Properties
Generator and Discriminator models were trained for 100 epochs. the difference between the generated images from epoch 75 onwards became negligible, indicating convergence. So the training was stopped at this stage.
However you can still load the pre-trained models by setting LOAD_MODEL to True in the `config.py` file. This will allow you to use the pre-trained weights and continue training the model with your own dataset or change the weights by fine-tuning the model as per your desires.
```
Model Properties = {

# The Model Consists of 2 Classes with below values for re-training/fine-tuning purposes

## ResnetGenerator
The `ResnetGenerator` class implements a ResNet-based generator for image translation tasks. It consists of ResNet blocks between downsampling and upsampling operations. Here are the key properties of the `ResnetGenerator`:

- **Input Channels:** 3 (RGB images)
- **Output Channels:** 3 (RGB images)
- **ngf (Number of Generator Filters):** 64
- **Normalization Layer:** Instance normalization
- **Use Dropout:** False
- **Number of ResNet Blocks:** 9
- **Padding Type:** Reflective padding
- **Final Activation:** Tanh

## ResnetBlock
The `ResnetBlock` class implements a single ResNet block, which consists of two convolutional layers with skip connections. Here are the key properties of the `ResnetBlock`:

- **Input/Output Channels:** Variable (depends on the input)
- **Padding Type:** Reflective padding
- **Normalization Layer:** Instance normalization
- **Use Dropout:** Variable (depends on the input)
- **Use Bias:** Variable (depends on the input)
}
```
Other thing you need to keep in mind while working with the model:
- **Image Preprocessing:** The input images are preprocessed using normalization with mean (0.5, 0.5, 0.5) and standard deviation (0.5, 0.5, 0.5).
- **Device:** The model is loaded onto the GPU if available; otherwise, it runs on the CPU.
- **Model Loading:** The model weights are loaded from a saved state dictionary (`SceneToPixel.pth`).
- **Image Size:** For some reason you may get a `torch.cuda.OutOfMemoryError` error when generating image (even though the model uses less than 4GBs of CUDA memory), to bypass that you simply resize the image to a smaller image.


## Acknowledgments
- This project was inspired by the original CycleGAN paper:
- [CycleGAN Papers](https://arxiv.org/abs/1703.10593)
- and this video: [Aladdin](https://www.youtube.com/watch?v=4LktBHGCNfw&t)
