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


## Model Files
Generator and Discriminator models were trained for 100 epochs. the difference between the generated images from epoch 75 onwards became negligible, indicating convergence. So the training was stopped at this stage.
However you can still load the pre-trained models by setting LOAD_MODEL to True in the `config.py` file. This will allow you to use the pre-trained weights and continue training the model with your own dataset or change the weights by fine-tuning the model as per your desires.
- **Generator Model (Domain A to Domain B)**: [Link to Model](https://drive.google.com/file/d/1-2mpCLqUsk_6MATAyBVYre4FSedP3nbl/view?usp=sharing)
- **Generator Model (Domain B to Domain A)**: [Link to Model](https://drive.google.com/file/d/1-BKtOW3XZQowwLlmzHbJM2iw5eFapnmL/view?usp=sharing)

## Acknowledgments
- This project was inspired by the original CycleGAN paper:
- [CycleGAN Papers](https://arxiv.org/abs/1703.10593)
- and this video: [Aladdin](https://www.youtube.com/watch?v=4LktBHGCNfw&t)
