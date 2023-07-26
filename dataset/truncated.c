#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int isTruncatedImage(const char* imagePath) {
    Mat image = imread(imagePath);
    if (image.empty()) {
        return 1;
    }
    return 0;
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
                if (isTruncatedImage(imagePath)) {
                    printf("Truncated image found: %s\n", imagePath);
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
