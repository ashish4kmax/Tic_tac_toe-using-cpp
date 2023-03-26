#include <iostream>
#include <vector>
using namespace std;

// X and O
bool check(vector<vector<char>> &tictac)
{
    if ((tictac[0][0] != '-' && tictac[1][1] != '-' && tictac[2][2] != '-') && (tictac[0][0] == tictac[1][1]) && (tictac[1][1] == tictac[2][2]))
    {
        return true;
    }
    else if ((tictac[0][2] != '-' && tictac[1][1] != '-' && tictac[2][0] != '-') && (tictac[0][2] == tictac[1][1]) && (tictac[1][1] == tictac[2][0]))
    {
        return true;
    }
    else if ((tictac[0][0] != '-' && tictac[0][1] != '-' && tictac[0][2] != '-') && (tictac[0][0] == tictac[0][1]) && (tictac[0][1] == tictac[0][2]))
    {
        return true;
    }
    else if ((tictac[1][0] != '-' && tictac[1][1] != '-' && tictac[1][2] != '-') && (tictac[1][0] == tictac[1][1]) && (tictac[1][1] == tictac[1][2]))
    {
        return true;
    }
    else if ((tictac[2][0] != '-' && tictac[2][1] != '-' && tictac[2][2] != '-') && (tictac[2][0] == tictac[2][1]) && (tictac[2][1] == tictac[2][2]))
    {
        return true;
    }
    else if ((tictac[0][0] != '-' && tictac[1][0] != '-' && tictac[2][0] != '-') && (tictac[0][0] == tictac[1][0]) && (tictac[1][0] == tictac[2][0]))
    {
        return true;
    }
    else if ((tictac[0][1] != '-' && tictac[1][1] != '-' && tictac[2][1] != '-') && (tictac[0][1] == tictac[1][1]) && (tictac[1][1] == tictac[2][1]))
    {
        return true;
    }
    else if ((tictac[0][2] != '-' && tictac[1][2] != '-' && tictac[2][2] != '-') && (tictac[0][2] == tictac[1][2]) && (tictac[1][2] == tictac[2][2]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void display(vector<vector<char>> &tictac)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << tictac[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string p1, p2;
    cout << "Enter player one name : ";
    cin >> p1;
    cout << "Enter player two's name : ";
    cin >> p2;
    vector<vector<char>> tictac;
    vector<char> temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp.push_back('-');
        }
        tictac.push_back(temp);
        temp.clear();
    }

    cout << "Given a layout of tic-tac-toe with positions you have to play : \n";
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << tictac[i][j] << "(" << i << j << ")"<< " ";
        }
        cout << endl;
    }

    char choice1, choice2;
    char random[2] = {'H', 'T'};
    cout << "choose head or tails" << endl;
    // H for head and T for tails;
    cout << "Player 1 choice : ";
    cin >> choice1;
    if (choice1 == 'H')
    {
        cout << "Player 2 gets Tails" << endl;
        choice2 = 'T';
    }
    else
    {
        cout << "Player 2 gets Heads" << endl;
        choice2 = 'H';
    }

    int lb = 0, ub = 1;
    char toss = random[(rand() % (ub - lb + 1)) + lb];

    cout << endl;
    cout << "Toss is = " << toss << endl;
    cout << endl;

    int pos1 = 0;
    int pos2 = 0;

    if (toss == 'H')
    {
        if (choice1 == 'H' && choice2 == 'T')
        {
            // Player-1 starts
            cout<<p1<<" wins the toss so he will start"<<endl;
            for (;;)
            {
                cout << "Enter the position to put X : " << endl;
                cin >> pos1 >> pos2;
                if((pos1<0 || pos1>2) && (pos2<0 || pos2>2)) {
                    cout<<"Opps out of bounds opponet gets the chance!!"<<endl;
                    goto pl1;
                }
                tictac[pos1][pos2] = 'X';
                count1++;
                if (count1 + count2 == 9)
                {
                    goto end;
                }
                display(tictac);
                if (check(tictac))
                {
                    cout << p1 << " wins!!";
                    goto end;
                }
                pl1:
                cout << "Enter the position to put O : " << endl;
                cin >> pos1 >> pos2;
                tictac[pos1][pos2] = 'O';
                count2++;
                display(tictac);
                if (check(tictac))
                {
                    cout << p2 << " wins!!";
                    goto end;
                }
            }
        }
        else if (choice1 == 'T' && choice2 == 'H')
        {
            // Player-2 starts
            cout << p2 << " wins the toss so he will start" << endl;
            for (;;)
            {
                cout << "Enter the position to put O : " << endl;
                cin >> pos1 >> pos2;
                if ((pos1 < 0 || pos1 > 2) && (pos2 < 0 || pos2 > 2))
                {
                    cout << "Opps out of bounds opponet gets the chance!!" << endl;
                    goto pl2;
                }
                tictac[pos1][pos2] = 'O';
                count1++;
                if (count1 + count2 == 9)
                {
                    goto end;
                }
                display(tictac);
                if (check(tictac))
                {
                    cout << p2 << " wins!!";
                    goto end;
                }
                pl2:
                cout << "Enter the position to put X : " << endl;
                cin >> pos1 >> pos2;
                tictac[pos1][pos2] = 'X';
                count2++;
                display(tictac);
                if (check(tictac))
                {
                    cout << p1 << " wins!!";
                    goto end;
                }
            }
        }
    }

    else if (toss == 'T')
    {
        if (choice1 == 'T' && choice2 == 'H')
        {
            // Player-1 starts
            cout << p1 << " wins the toss so he will start" << endl;
            for (;;)
            {
                cout << "Enter the position to put X : " << endl;
                cin >> pos1 >> pos2;
                if ((pos1 < 0 || pos1 > 2) && (pos2 < 0 || pos2 > 2))
                {
                    cout << "Opps out of bounds opponet gets the chance!!" << endl;
                    goto pl3;
                }
                tictac[pos1][pos2] = 'X';
                count1++;
                if (count1 + count2 == 9)
                {
                    goto end;
                }
                display(tictac);
                if (check(tictac))
                {
                    cout << p1 << " wins!!";
                    goto end;
                }
                pl3:
                cout << "Enter the position to put O : " << endl;
                cin >> pos1 >> pos2;
                tictac[pos1][pos2] = 'O';
                count2++;
                display(tictac);
                if (check(tictac))
                {
                    cout << p2 << " wins!!";
                    goto end;
                }
            }
        }
        else if (choice1 == 'H' && choice2 == 'T')
        {
            // Player-2 starts
            cout << p2 << " wins the toss so he will start" << endl;
            for (;;)
            {
                cout << "Enter the position to put O : " << endl;
                cin >> pos1 >> pos2;
                if ((pos1 < 0 || pos1 > 2) && (pos2 < 0 || pos2 > 2))
                {
                    cout << "Opps out of bounds opponet gets the chance!!" << endl;
                    goto pl4;
                }
                tictac[pos1][pos2] = 'O';
                count1++;
                if (count1 + count2 == 9)
                {
                    goto end;
                }
                display(tictac);
                if (check(tictac))
                {
                    cout << p2 << " wins!!";
                    goto end;
                }
                pl4:
                cout << "Enter the position to put X : " << endl;
                cin >> pos1 >> pos2;
                tictac[pos1][pos2] = 'X';
                count2++;
                display(tictac);
                if (check(tictac))
                {
                    cout << p1 << " wins!!";
                    goto end;
                }
            }
        }
    }

    end:
    return 0;
}
