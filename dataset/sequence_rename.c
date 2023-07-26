#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

int main() {
    const char* directoryPath = "train/pixel"; // Replace with the path to your directory
    DIR *dir;
    struct dirent *ent;
    int count = 1;

    if ((dir = opendir(directoryPath)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            const char* oldName = ent->d_name;
            if (strstr(oldName, ".jpg") || strstr(oldName, ".jpeg") || strstr(oldName, ".png")) {
                char newName[256];
                snprintf(newName, sizeof(newName), "%s/%d.png", directoryPath, count);
                char oldPath[256], newPath[256];
                sprintf(oldPath, "%s/%s", directoryPath, oldName);
                sprintf(newPath, "%s/%s", directoryPath, newName);
                if (rename(oldPath, newPath) == 0) {
                    printf("Renamed '%s' to '%s'\n", oldName, newName);
                    count++;
                } else {
                    perror("Error renaming file");
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
