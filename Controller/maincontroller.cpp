#include "maincontroller.h"

MainController::MainController() {
}

void MainController::Route(string controller,string method) {
    // if(!this->regFlag){
    //     this->RegUser();
    //     return;
    // }
    string extension = ".so";
    string designation = "controller";
    DIR *dir;
    struct dirent *ent;

    dir = opendir("../../Controller/");
    if (dir == nullptr) {
        perror("Ошибка открытия директории");
        return;
    }

    if (dir != nullptr) {
        while ((ent = readdir(dir)) != nullptr) {
            string tmp = ent->d_name;

            if (/*tmp.find(controller) != std::string::npos &&*/ tmp.find(extension) != std::string::npos) {

                string path = "../../Controller/" + tmp;

                void* handle = dlopen(path.c_str(), RTLD_LAZY);
                if (!handle) {
                    perror("Не удалось загрузить библиотеку");
                    continue;
                }
                typedef void (*StaticMethodType)();
                StaticMethodType staticMethod = (StaticMethodType)dlsym(handle, method.c_str());
                const char* dlsym_error = dlerror();
                if (dlsym_error) {
                    perror("Не удалось найти метод");
                    dlclose(handle);
                    continue;
                }

                staticMethod();

                dlclose(handle);
            }
        }
    }
}

void MainController:: RegUser() {}
