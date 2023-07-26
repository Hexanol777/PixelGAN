#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <opencv2/opencv.hpp>

using namespace cv;

void resizeImageTo512x512(const char* imagePath) {
    Mat image = imread(imagePath);
    if (image.empty()) {
        printf("Error: Unable to read image '%s'\n", imagePath);
        return;
    }

    if (image.cols != 512 || image.rows != 512) {
        resize(image, image, Size(512, 512));
        imwrite(imagePath, image);
        printf("Resized image '%s' to 512x512\n", imagePath);
    }
}

int main() {
    const char* directoryPath = "train/pixel"; // Replace with the path to your directory
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(directoryPath)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            const char* imageName = ent->d_name;
            const char* imagePath = (std::string(directoryPath) + "/" + imageName).c_str();

            if (strstr(imageName, ".jpg") || strstr(imageName, ".jpeg") || strstr(imageName, ".png")) {
                Mat image = imread(imagePath);
                if (!image.empty() && image.cols != 512 && image.rows != 512) {
                    printf("Found image '%s' with dimensions %dx%d\n", imageName, image.cols, image.rows);
                    resizeImageTo512x512(imagePath);
                }
            }
        }
        closedir(dir);
    } else {
        perror("Error: Unable to open directory");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
