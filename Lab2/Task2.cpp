#include <iostream>
using namespace std;

int main(){
    int rows, cols;
    cout << "Enter the number of benches and seats: ";
    cin >> rows >> cols;
    int **classroom = new int*[rows];
    for(int i = 0; i < rows; i++){
        classroom[i] = new int[cols];
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            classroom[i][j] = 0;
        }
    }
    int bench, seat, flag = 1;

    while(flag == 1){
        cout << "Do you want to fill seat?(Enter '0' for'No' or '1' for 'Yes': ";
        cin >> flag;
        if(flag == 1){
            cout << "Enter the bench and seat number: ";
            cin >> bench >> seat;
            if((bench > 0 && bench <= rows) && (seat > 0 && seat <= cols)){
                if (classroom[bench - 1][seat - 1] == 1){
                    cout << "The seat is already filled.\n";
                }
                else{
                    classroom[bench - 1][seat - 1] = 1;
                }
                
            }
            else{
                cout << "Please enter the bench number from 1 to " << rows << " and seat number from 1 to " << cols << ".\n";
            }
        } 
        else if(flag == 0){
            cout << "Classroom Seating Chart:\n";
            for (int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    cout << classroom[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "Please enter '0' for 'No' or '1' for 'Yes'.\n";
        }
    }
    return 0;
}