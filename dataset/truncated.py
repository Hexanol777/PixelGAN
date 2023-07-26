from PIL import Image
import os

def check_truncated_images(root_dir):
    corrupted_images = []

    for root, _, files in os.walk(root_dir):
        for filename in files:
            image_path = os.path.join(root, filename)
            try:
                with Image.open(image_path) as img:
                    img.verify()  # Verify if the image is valid
                    print(image_path)
            except (IOError, SyntaxError, OSError) as e:
                print(f"Corrupted image found: {filename}")
                print(f"Image path: {image_path}")
                corrupted_images.append(image_path)

    return corrupted_images

if __name__ == "__main__":
    dataset_root = "train/scenery"  # Replace this with the root directory of your dataset
    corrupted_images = check_truncated_images(dataset_root)

    if not corrupted_images:
        print("No corrupted images found in the dataset.")
    else:
        print("Corrupted images found in the dataset:")
        for img_path in corrupted_images:
            print(img_path)
