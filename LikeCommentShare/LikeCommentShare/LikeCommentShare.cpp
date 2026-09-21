//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm> // for sort
//
//using namespace std;
//
//// Structure to hold team information
//struct Team {
//    string name;
//    int score;
//
//    // Constructor to initialize the team
//    Team(string n, int s) : name(n), score(s) {}
//};
//
//// Function to calculate the score based on likes, comments, and shares
//int calculateScore(int likes, int comments, int shares) {
//    return likes + 2 * comments + 3 * shares;
//}
//
//// Comparator for sorting teams by score
//bool compareTeams(const Team& a, const Team& b) {
//    return a.score > b.score; // Sort in descending order
//}
//
//int main() {
//    vector<Team> teams;
//    string teamName;
//
//    while (true) {
//        cin >> teamName; // Read team name
//        if (teamName == "000") break; // End of input
//
//        int likes, comments, shares;
//        cin >> likes >> comments >> shares; // Read interactions
//
//        // Calculate score for the team
//        int score = calculateScore(likes, comments, shares);
//
//        // Create team object and add to the list
//        teams.push_back(Team(teamName, score));
//    }
//
//    // Sort teams based on their scores
//    sort(teams.begin(), teams.end(), compareTeams);
//
//    // Output the names of the top 3 teams
//    for (int i = 0; i < 3 && i < teams.size(); ++i) {
//        cout << teams[i].name << endl;
//    }
//
//    return 0;
//}
