#include <map>
#include <ctime>
using ll = long long;
using namespace std;

//  sau đây là các đoạn code được nhóm tham khảo

// lấy thời gian thực 
string thoigian_hientai(){
    time_t hien_tai = time(nullptr);
    string thoi_gian = ctime(&hien_tai);
    if (!thoi_gian.empty() && thoi_gian.back() == '\n') {
        thoi_gian.pop_back(); 
    }
    return thoi_gian;
}

// struct tm 
 time_t dinh_dang_thoi_gian(const string &time){
            struct tm tm = {0};

            string thu, thang;    // thang = "May"
            int ngay, gio, phut, giay, nam;
            stringstream ss(time);

            ss >> thu >> thang >> ngay >> gio;
            ss.ignore();
            ss >> phut;
            ss.ignore();
            ss >> giay >> nam;
            
            map<string, int> mon_of_y = {
                {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6},
                {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
            };
            int thang_hien_tai = mon_of_y[thang];    

            tm.tm_mon = thang_hien_tai - 1;
            tm.tm_mday = ngay;
            tm.tm_hour = gio;
            tm.tm_min = phut;
            tm.tm_sec = giay;
            tm.tm_year = nam - 1900;
            return mktime(&tm);
}

//hàm difftime
double so_giay = difftime(t2, t1); 

// chữ hiện màu 
cout << "\e[31m" << "0. Dang xuat\n" << "\e[0m";


int main() {
    
    return 0;
}