#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long int journeyToMoon(int n, vector<vector<int>> astronaut) {
    int len=astronaut.size();
    bool visited[n]={false};
    vector<int>a[n];
    for(int i=0;i<len;i++){
        a[astronaut[i][0]].push_back(astronaut[i][1]);
        a[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    long int sum = 0;
    long int result = 0;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            int loc_count=1;
            queue<int>q;
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                int t=q.front();
                q.pop();
                for(int ele : a[t]){
                    if(visited[ele]==false){
                        q.push(ele);
                        visited[ele]=true;
                        loc_count+=1;
                    }
                }

            }
            result += sum*loc_count;
            sum+=loc_count;
        } 
    }  
    return result;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

