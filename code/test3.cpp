#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <filesystem>
#include <conio.h>
#include <windows.h> 
#include <map>
using ll = long long;
using namespace std;


class thong_tin_nguoi{
    protected:
        string ID;    // lay id lam thong tin dang nhap
        string hoten;
        string ngaysinh;
        string gioitinh;
        string sdt;
        string gmail;
        string password;
        long long balance;  //so du
    public:
        // A_admin   _admin = 6 ki tu    A_admin
        bool dinh_dang_id_admin(const string &id_admin){
            if(id_admin.size() < 6) return false;
            string cuoi_id = id_admin.substr(id_admin.size() - 6);   // cuoi_id = _admin
            return cuoi_id == "_admin";
        }
        //00/00/0000
        bool dinh_dang_ngay_sinh(const string &ngaysinh){
            if((ngaysinh[2] != '/' && ngaysinh[5] != '/') || ngaysinh.size() != 10){
                return false;
            }
            return true;
        }

        bool dinh_dang_gioi_tinh(const string &gioitinh){
            return gioitinh == "nam" || gioitinh == "nu";
        }

        bool dinh_dang_sdt(const string &sdt){
            if(sdt.size() != 10 || sdt[0] != '0') return false;
            for(char c : sdt){
                if(!isdigit(c)) return false;
            }
            return true;
        }

        bool dinh_dang_gmail(const string &gmail){
            if(gmail.size() < 10) return false;
            string cuoi_gmail = gmail.substr(gmail.size() - 10);   // cuoi_id = _admin
            return cuoi_gmail == "@gmail.com";
        }

        bool dinh_dang_mk(const string &mk){
            return mk.size() >= 7;
        }

        string dinh_dang_tien(long long &tien){
            string money = to_string(tien);
            reverse(money.begin(), money.end());
            for(size_t i = 3; i < money.size(); i += 4){
                money.insert(i, ".");
            }
            reverse(money.begin(), money.end());
            return money;
        }
        
        void information(){
            cout << "Nhap ID: ";
            cin.ignore();
            getline(cin, ID);
            cout << "Nhap ho ten: ";
            getline(cin, hoten); 
            
            do
            {
                cout << "Nhap ngay sinh: ";
                getline(cin, ngaysinh);
                if(!dinh_dang_ngay_sinh(ngaysinh)){
                    cout << "Ngay sinh khong hop le, nhap lai...\n";
                }
            } while (!dinh_dang_ngay_sinh(ngaysinh));
           
            do
            {
                cout << "Nhap gioi tinh: ";
                getline(cin, gioitinh);
                if(!dinh_dang_gioi_tinh(gioitinh)){
                    cout << "Gioi tinh khong hop le, nhap lai...\n";
                }
            } while (!dinh_dang_gioi_tinh(gioitinh));
            
            do
            {
                cout << "Nhap gmail: ";
                getline(cin, gmail);
                if(!dinh_dang_gmail(gmail)){
                    cout << "Gmail khong hop le, nhap lai...\n";
                }
            } while (!dinh_dang_gmail(gmail));
            
            do
            {
                cout << "Nhap so dien thoai: ";
                getline(cin, sdt);
                if(!(dinh_dang_sdt(sdt))){
                    cout << "Sai dinh dang, nhap lai...\n";
                }
            } while (!(dinh_dang_sdt(sdt)));
            
            do
            {   
                cout << "Nhap mat khau (nhieu hon 7 ki tu): ";
                getline(cin, password);
                if(!dinh_dang_mk(password)){
                    cout << "Mat khau qua ngan, nhap lai....\n";
                }
            } while (!dinh_dang_mk(password));   

            balance = 0;
        }

        bool kt_trungTaiKhoan(const string ID, const string &file_admin, const string &file_users){
            for(const string &ten_file : {file_admin, file_users}){
                ifstream infile(ten_file);
                string dong;
                while(getline(infile, dong)){     // getline(cin, )
                    stringstream ss(dong);
                    string check_id;
                    if(getline(ss, check_id, '|')){
                        if(ID == check_id){
                            return true;
                        }
                    }
                }
                infile.close();
            }
            return false;
        }
        

        bool save_info(const string &file_ghi, const string &file_admin, const string &file_users) {
            if (kt_trungTaiKhoan(ID, file_admin, file_users)) {
                cout << "ID da ton tai, vui long nhap ID khac...\n";
                return false;
            }
            ofstream outfile(file_ghi, ios::app);
            if (!outfile.is_open()) {
                cout << "Khong mo duoc file...\n";
                return false;
            }
        
            outfile << ID << "|" << password << "|" << hoten << "|" << gioitinh << "|" << ngaysinh << "|"
                    << sdt << "|" << gmail << "|" << balance << endl;

            outfile.close();
            return true;
        }

        string get_ID() const {return ID;}
        string get_hoten() const {return hoten;}   
        string get_ngaysinh() const {return ngaysinh;}
        string get_gioi_tinh() const {return gioitinh;}
        string get_sdt() const {return sdt;}
        string get_gmail() const {return gmail;}
        string get_password() const {return password;}
        int get_tien() const {return balance;}

        void set_ID(const string& newID) { ID = newID; }
        void set_hoten(const string& newHoten) { hoten = newHoten; }
        void set_ngaysinh(const string& newNgaysinh) { ngaysinh = newNgaysinh; }
        void set_gioi_tinh(const string& newGioitinh) { gioitinh = newGioitinh; }
        void set_sdt(const string& newSdt) { sdt = newSdt; }
        void set_gmail(const string& newGmail) { gmail = newGmail; }
        void set_password(const string& newPassword) { password = newPassword; }
        void set_tien(int newBalance) { balance = newBalance; }
};

class thong_tin_xe{

};

class bai_xe : public thong_tin_nguoi, public thong_tin_xe{
    private:
    public:
};

class system_function_control : public bai_xe{
    private:
        string id_hien_tai;  
        vector<thong_tin_nguoi> tt_admin;   // luu thong 
        vector<thong_tin_nguoi> tt_nhanvien;  
    public: 
        
        void clean_display(){
            #ifdef _WIN32
                system("cls");
            #endif
        }

        system_function_control(){
            load_data_people("account_of_admin.txt", tt_admin);
            load_data_people("account_of_users.txt", tt_nhanvien);
        }

        void load_data_people(const string &ten_file, vector<thong_tin_nguoi> &ds_people){
            ifstream infile(ten_file);
            string dong;
            if(!infile.is_open()){
                cout << "He thong loi, cho it phut...\n";
                system("pause");
                return;
            }

            while(getline(infile, dong)){
                stringstream ss(dong);
                string id, mk, ten, gioitinh, ngaysinh, sdt, gmail, so_du;
                if(getline(ss, id, '|') && getline(ss, mk, '|') && getline(ss, ten, '|') && getline(ss, gioitinh, '|') && getline(ss, ngaysinh,'|')
                    && getline(ss, sdt, '|') && getline(ss, gmail, '|') && getline(ss, so_du)){
                    thong_tin_nguoi people;
                    people.set_ID(id);
                    people.set_password(mk);
                    people.set_hoten(hoten);
                    people.set_gioi_tinh(gioitinh);
                    people.set_ngaysinh(ngaysinh);
                    people.set_sdt(sdt);
                    people.set_gmail(gmail);
                    people.set_tien(stoi(so_du));
                    ds_people.push_back(people);
                }
            }
        }      


        void control_users(){
        int choice;

        // thong_tin_nguoi* thong_tin = tim_tt_id(tt_nhan_vien, id_hien_tai);
        do
        {
            clean_display();

            cout << "====================== HE THONG DANG KI GIU XE THONG MINH ======================\n";
            // cout << "Xin chao [ " << thong_tin->get_hoten() << " ] he thong da san sang, chuc ban ngay moi tot lanh!!!\n";
            // cout << setw(15) << " " << "SO LUONG PHUONG TIEN DANG GUI TRONG BAI XE: " << endl;
            // cout << setw(34) <<"XE MAY: " << so_luong_pt_dang_gui("xe may") << " | 100\n";
            // cout << setw(34) << "XE OTO: " << so_luong_pt_dang_gui("xe oto") << " | 100\n" << endl;
            cout << "1. Them phuong tien\n";
            cout << "2. Dang ki giu xe\n";
            cout << "3. Danh sach xe da dang ki\n";
            cout << "4. Danh sach xe hien dang duoc giu\n";
            cout << "5. Thong tin ca nhan\n";
            cout << "6. Nap tien\n";
            cout << "7. Lay xe\n";
            cout << "8. Chinh sua thong tin\n";
            cout << "0. Dang xuat\n";
            cout << "-------> Nhap so de chon chuc nang: "; 
            cin >> choice;

            clean_display();

            switch(choice) {
                case 1:
                    // chon_phuong_tien();
                    break;
                case 2:
                    // phan_loai_dk_xe();
                    break;
                case 3:
                    // quan_li_bai_xe.DS_phuongtien_ca_nhan(id_hien_tai);
                    system("pause");
                    break;
                case 4:
                    // DS_pt_danh_gui();
                    break;
                case 5:
                    // display_information();
                    system("pause");
                    break;
                case 6:
                    // nap_tien();
                    break;
                case 7:
                    // xu_li_lay_xe();
                    break;
                case 8:
                    // chinh_sua_thong_tin();
                    break;
                case 0:
                    cout << "Dang xuat thanh cong...\n";
                    system("pause");
                    break;
                default:
                    cout << "Nhap lai...\n";
                    break;
            }

        }while (choice != 0); 
    }


    string che_mk(){
        string password;
        char ch;

        while(true){
            ch = _getch();

            if(ch == 13){
                cout << endl;
                break;
            }else if(ch == 8){
                if(!password.empty()){
                    password.pop_back();
                    cout << "\b \b";
                }
            }else if((ch >= 32 && ch <= 126)){
                password += ch;
                cout << "*";
            }
        }
        return password;
    }


    bool check_tt_dang_ki(const string &id, const string &mk, vector<thong_tin_nguoi> &tt_people){
        for(auto &people : tt_people){
            if(people.get_ID() == id && people.get_password() == mk){
                // id_hien_tai = id;
                return true;
            }
        }
        return false;   
    }
   

    void dang_nhap(){
        cout << "=========== DANG NHAP ===========\n";
        string id, password;
        cout << "Nhap ID: ";
        cin.ignore();
        getline(cin, id);
        cout << "Mat khau: ";
        password = che_mk();

        if(dinh_dang_id_admin(id)){  //admin
            if(check_tt_dang_ki(id, password, tt_admin)){
                cout << "Dang nhap thanh cong...\n";
                system("pause");
                // control_admin();
            }else{
                cout << "Sai thong tin dang nhap, nhap lai...\n";
                system("pause");
            }
        }else{
            if(check_tt_dang_ki(id, password, tt_nhanvien)){
                cout << "Dang nhap thanh cong...\n";
                system("pause");
                control_users();
            }else{
                cout << "Sai thong tin dang nhap, nhap lai...\n";
                system("pause");
            }
        }
    }

    void dang_ki(){
        thong_tin_nguoi people;
        people.information();

        if(dinh_dang_id_admin(people.get_ID())){
            if(people.save_info("account_of_admin.txt", "account_of_admin.txt", "account_of_users.txt")){
                tt_admin.push_back(people);
            }
        }else{
            if(people.save_info("account_of_users.txt", "account_of_admin.txt", "account_of_users.txt")){
                tt_nhanvien.push_back(people);
            }
        }
        cout << "Dang ki thanh cong...\n";
        system("pause");
    }

    void menu_register(){
        int choice;
        do
        {
            clean_display();
            cout << "================ HE THONG BAI XE THONG MINH ================\n";
            cout << "1. Dang ki\n";
            cout << "2. Dang nhap\n";
            cout << "---------> Nhap so de chon chuc nang: ";
            cin >> choice;
            clean_display();

            switch (choice)
            {
            case 1:
                dang_ki();
                break;
            case 2:
                dang_nhap();
                break;
            default:
                break;
            }
        } while (choice != 0);
        
    }
};


int main() {
    system_function_control quan_li;
    quan_li.menu_register();
    return 0;
}