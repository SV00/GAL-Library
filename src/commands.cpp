#include <iostream>
#include <bits/stdc++.h>
#include "all-headers.h"

using namespace std;

void parse_user_input(vector <string> *userinput){
    if(userinput->size() != 0){
        for(int i = userinput->size() - 1; i >= 0; i--){
            userinput->pop_back();
        }
    }
    string input, call;
    printf("\x01b[1;38;5;3mFunction: \x1b[0m"); fflush(stdin); getline(cin, input);
    stringstream check(input);

    while(getline(check, call, ' ')){
        (*userinput).push_back(call);
    }
}

void function_call(Lists list){
    string name;
    vector <string> userinput;
    do{ 
        parse_user_input(&userinput);

        if(userinput[0] == "new"){
            if(userinput[1] == "matrix"){
                list->Mlist = command_new_matrix(list->Mlist);
            } else if(userinput[1] == "vector"){
                list->Vlist = command_new_vector(list->Vlist);
            } else if(userinput[1] == "system"){
                list->Eqlist = command_new_system(list->Eqlist);
            } else if(userinput[1] == "base"){
                list->Blist = command_new_base(list->Blist);
            } else {
                cout << "Invalid function call" << endl << endl;
            }
        } else if(userinput[0] == "calculate"){
            if(userinput[1] == "matrix"){
                if(userinput[2] == "product"){
                    list->Mlist = command_matrix_product(list->Mlist);
                } else if(userinput[2] == "sum"){
                    list->Mlist = command_matrix_sum(list->Mlist);
                } else if(userinput[2] == "difference"){
                    list->Mlist = command_matrix_difference(list->Mlist);
                } else if(userinput[2] == "transpose"){
                    list->Mlist = command_matrix_traspose(list->Mlist);
                } else if(userinput[2] == "scalar"){
                    list->Mlist = command_matrix_scalar_mult(list->Mlist);
                } else if(userinput[2] == "stairs"){
                    list->Mlist = command_matrix_stairs(list->Mlist);
                } else if (userinput[2] == "rref"){
                    list->Mlist = command_matrix_rref(list->Mlist);
                } else if(userinput[2] == "rank"){
                    command_matrix_rank(list->Mlist);
                } else if(userinput[2] == "base"){
                    command_matrix_is_base(list->Mlist);
                } else if(userinput[2] == "det"){
                    command_matrix_det(list->Mlist);
                } else {
                    cout << "Invalid function call" << endl << endl;
                }
            } else if(userinput[1] == "vector"){
                if(userinput[2] == "scalar"){
                    command_fvector_scalar_product(list->Vlist);
                } else if(userinput[2] == "sum"){
                    list->Vlist = command_fvector_sum(list->Vlist);
                } else if(userinput[2] == "difference"){
                    list->Vlist = command_fvector_difference(list->Vlist);
                } else if(userinput[2] == "norm"){
                    command_fvector_norm(list->Vlist);
                } else if(userinput[2] == "angle"){
                    command_fvector_angle(list->Vlist);
                } else {
                    cout << "Invalid input" << endl << endl;
                }
            } else if(userinput[1] == "system"){
                if(userinput[2] == "solution"){
                    list->Eqlist = command_system_solution(list->Eqlist);
                } else if(userinput[2] == "build"){
                    list = command_system_build(list);
                }
            } else {
                cout << "Invalid function call" << endl << endl;
            }
        } else if(userinput[0] == "print"){
            if(userinput[1] == "matrix"){
                command_print_matrix(list->Mlist);
            } else if(userinput[1] == "vector"){
                command_print_vector(list->Vlist);
            } else if(userinput[1] == "system"){
                command_print_system(list->Eqlist);
            } else if(userinput[1] == "base"){
                command_print_base(list->Blist);
            } else {
                cout << "Invalid function call" << endl << endl;
            }
        } else if(userinput[0] == "remove"){
            if(userinput[1] == "matrix"){
                list->Mlist = remove_search(list->Mlist);
            } else if(userinput[1] == "vector"){
                list->Vlist = remove_vsearch(list->Vlist);
            } else if(userinput[1] == "system"){
                list->Eqlist = remove_esearch(list->Eqlist);
            } else if(userinput[1] == "base"){
                list->Blist = remove_bsearch(list->Blist);
            }
        } else {
            if(userinput[0] != "END")
                cout << "No such function" << endl << endl;
        }

    }while(userinput[0] != "END");
}