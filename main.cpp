#include <iostream>
#include <vector>
#include <sstream>
#include <string>


using namespace std;

    string cipherInput;                                                                                                     //declare variables
    int i, n, convertedNum;


            string ROT13(string cipherInput) {                                                                              //function for ROT13 cipher

                string shifted;

                for (auto const &ch : cipherInput) {                                                                        //for loop which shifts all letters and wraps 'z' back around to 'a'
                    if (islower(static_cast<char unsigned>(ch)))
                        shifted += 'a' + (ch - 'a' + 13) % ('z' - 'a' + 1);

                    if (isupper(static_cast<char unsigned>(ch)))
                        (shifted += 'A' + (ch - 'A' + 13) % ('Z' - 'A' + 1));
                }

                return shifted;                                                                                             //return result of letter shifting
            }




            string ROT6(string cipherInput) {                                                                               //function for ROT6 cipher

                string shifted;

                for (auto const &ch : cipherInput) {
                    if (islower(static_cast<char unsigned>(ch)))
                        shifted += 'a' + (ch - 'a' - 6) % ('z' - 'a' + 1);

                    if (isupper(static_cast<char unsigned>(ch)))
                        (shifted += 'A' + (ch - 'A' - 6) % ('Z' - 'A' + 1));
                }

                return shifted;
            }


            char nth_letter(int n){                                                                                         //function for custom cipher
                for(n >= 1 && n <= 26;;) {                                                                                   //run loop for each letter of the alphabet
                    return "abcdefghijklmnopqrstuvwxyz"[n - 1];
                }
            }





    int main(){

        string listSelect;


        cout << "Choose the number of which cipher you would like to use: " << endl;                                        //ask user to choose which cipher to use to decode message
        cout << "1. ROT13" << endl;
        cout << "2. ROT6" << endl;
        cout << "3. Custom" << endl;
        cin >> listSelect;                                                                                                  //take input to listSelect variable

        if (listSelect == "1" || listSelect == "1." || listSelect == "ROT13") {

            while(true) {
                cout << "Please enter the message you wish to be decoded. Enter 'done' when finished. " << endl;            //ask for input of encoded message
                cin >> cipherInput;                                                                                         //take input to cipherInput variable
                string storageArray[] {cipherInput};                                                                        //initialize an array to store the original coded message
                for(string s : storageArray)                                                                                //output original word to show what it decodes from
                    cout << "The original word was: " << s << endl;
                cout << "Which decodes to: " << ROT13(cipherInput) << endl;                                                 //output result of conversion function
                if(cipherInput == "done" || cipherInput == "Done"){
                    cout << "Finished" << endl;
                    return 0;
                }
            }
        }

        if (listSelect == "2" || listSelect == "2." || listSelect == "ROT6"){

            while(true) {
                cout << "Please enter the message you wish to be decoded. Enter 'done' when finished. " << endl;
                cin >> cipherInput;
                string storageArray[] {cipherInput};
                for(string s : storageArray)
                    cout << "The original word was: " << s << endl;
                cout << "Which decodes to: " << ROT6(cipherInput) << endl;
                if(cipherInput == "done" || cipherInput == "Done"){
                    cout << "Finished" << endl;
                    return 0;
                }
            }
        }

        if (listSelect == "3" || listSelect == "3." || listSelect == "custom"){

            while(true) {
                cout << "Please enter the message you wish to be decoded. Enter '0' when finished. " << endl;               //ask for user input
                cin >> n;                                                                                                   //take input to n variable
                convertedNum = (2 * n) - 1;                                                                                 //convert input with conversion equation
                int storageArray[] {convertedNum};                                                                          //store converted numbers in an array
                for(int s : storageArray)
                    cout << "The original code was: " << s << endl;
                cout << "Which decodes to: " << nth_letter(convertedNum) << endl;                                           //output decoded numbers as a word
                if(i == 0){                                                                                                 //end loop if input is '0'
                    cout << "Finished" << endl;
                    return 0;
                }
            }
        }


    }

