#include "DataManagement.h"


DataManagement::DataManagement(){
    Run();
    cout << "Data saved successfully! "<<endl;
    getch();

}

DataManagement::~DataManagement(){

}


/** @brief Save Data
 *  A function to coppy data to backup folder
 *  @author Phong
 */
void DataManagement::SaveData(string path_file, string backup_dir){

    ifstream    inFile(path_file);
    ofstream    outFile(backup_dir);

    outFile << inFile.rdbuf();
}


/** @brief get current working directory
 *  A function to get working folder
 *  @return string -> path of current working directory
 *  @author Phong
 */
string DataManagement::GetCurrentWorkingDirectory()
{
    char* cwd = _getcwd( 0, 0 ) ;
    std::string working_directory(cwd) ;
    std::free(cwd) ;
    
    string DataFolder = working_directory + "\\RawDatas\\";

    return DataFolder ;
}


/** @brief get list file in order to copy
 *  A function to list file need to copy and call func copy file to backup folder
 *  @author Phong
 */
void DataManagement::GetListFile(const char* path, string backup_dir) {
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        char* file_save = new char[255];
        sprintf(file_save, "%s\\%s", path, entry->d_name );

        string save_dir = backup_dir + "\\" + entry->d_name;

        SaveData(file_save, save_dir);
    }



    closedir(dir);
}


/** @brief create backup folder
 *  A function to create backup folder
 *  @return string -> path of backup folder
 *  @author Phong
 */
string DataManagement::CreateBackupFolder(){
    string nowTime = GetCurrentDateTime();
      
    
    string path = "D:\\BackUpData\\" + nowTime;   
    mkdir(path.c_str());

    return path;
}


/** @brief get current time
 *  A function to get current time
 *  @return string -> current time
 *  @author Phong
 */
const string DataManagement::GetCurrentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);

    return buf;
}

/** @brief execute function to save data
 *  A function to execute function to save data
 *  @author Phong
 */
void DataManagement::Run(){

    string backup_directory = CreateBackupFolder();

    string current_directory_temp = GetCurrentWorkingDirectory();

    const char *current_directory = current_directory_temp.c_str();

    GetListFile(current_directory, backup_directory);

}