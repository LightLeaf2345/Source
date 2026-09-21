#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>  
using namespace std;

struct Movie {
    string name;
    string genre;
    string director;
    string maleLead;
    string femaleLead;
    int year;

    Movie(string n, string g, string d, string ml, string fl, int y)
        : name(n), genre(g), director(d), maleLead(ml), femaleLead(fl), year(y) {}
};

template <typename DataType>
struct Node {
    DataType _data;
    Node* _pNext;

    Node(DataType data) : _data(data), _pNext(nullptr) {}
};

template <typename DataType>
class LinkedList {
private:
    Node<DataType>* _pHead;
    Node<DataType>* _pTail;
    int _iSize;

public:
    LinkedList() : _pHead(nullptr), _pTail(nullptr), _iSize(0) {}

    ~LinkedList() {
        clear();
    }

    void addTail(DataType data) {
        Node<DataType>* newNode = new Node<DataType>(data);
        if (!_pHead) {
            _pHead = newNode;
            _pTail = newNode;
        }
        else {
            _pTail->_pNext = newNode;
            _pTail = newNode;
        }
        _iSize++;
    }

    void display() {
        Node<DataType>* pWalker = _pHead;
        while (pWalker) {
            cout << "Name: " << pWalker->_data.name
                << ", Genre: " << pWalker->_data.genre
                << ", Director: " << pWalker->_data.director
                << ", Male Lead: " << pWalker->_data.maleLead
                << ", Female Lead: " << pWalker->_data.femaleLead
                << ", Year: " << pWalker->_data.year << endl;
            pWalker = pWalker->_pNext;
        }
    }

    void updateGenre(const string& movieName, const string& newGenre) {
        Node<DataType>* pWalker = _pHead;
        while (pWalker) {
            if (pWalker->_data.name == movieName) {
                pWalker->_data.genre = newGenre;
                return;
            }
            pWalker = pWalker->_pNext;
        }
    }

    void writeToFile(const string& filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }
        Node<DataType>* pWalker = _pHead;
        while (pWalker) {
            outFile << pWalker->_data.name << "#"
                << pWalker->_data.genre << "#"
                << pWalker->_data.director << "#"
                << pWalker->_data.maleLead << "#"
                << pWalker->_data.femaleLead << "#"
                << pWalker->_data.year << endl;
            pWalker = pWalker->_pNext;
        }
        outFile.close();
    }

    void saveMoviesByActor(const string& actorName) {
        ofstream outFile(actorName + ".txt");
        if (!outFile) {
            cerr << "Error opening file for actor: " << actorName << endl;
            return;
        }
        Node<DataType>* pWalker = _pHead;
        while (pWalker) {
            if (pWalker->_data.maleLead == actorName || pWalker->_data.femaleLead == actorName) {
                outFile << pWalker->_data.name << endl;
            }
            pWalker = pWalker->_pNext;
        }
        outFile.close();
    }

    void saveMoviesByDirector() {
        Node<DataType>* pWalker = _pHead;
        while (pWalker) {
            string directorFileName = pWalker->_data.director + ".txt";
            ofstream outFile(directorFileName, ios::app);
            if (!outFile) {
                cerr << "Error opening file for director: " << pWalker->_data.director << endl;
                return;
            }
            outFile << "Name: " << pWalker->_data.name
                << ", Genre: " << pWalker->_data.genre
                << ", Year: " << pWalker->_data.year << endl;
            outFile.close();
            pWalker = pWalker->_pNext;
        }
    }

    void saveLatestMovies(const string& filename) {
        vector<DataType> movies;
        Node<DataType>* pWalker = _pHead;
        while (pWalker) {
            movies.push_back(pWalker->_data);
            pWalker = pWalker->_pNext;
        }

        sort(movies.begin(), movies.end(), [](const DataType& a, const DataType& b) {
            return a.year > b.year;  
            });

        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }
        for (size_t i = 0; i < min<size_t>(3, movies.size()); i++) {
            outFile << movies[i].name << "#"
                << movies[i].genre << "#"
                << movies[i].director << "#"
                << movies[i].maleLead << "#"
                << movies[i].femaleLead << "#"
                << movies[i].year << endl;
        }
        outFile.close();
    }

    void clear() {
        while (_pHead) {
            Node<DataType>* temp = _pHead;
            _pHead = _pHead->_pNext;
            delete temp;
        }
        _pTail = nullptr;
        _iSize = 0;
    }
};

void readMoviesFromFile(LinkedList<Movie>& movieList, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name, genre, director, maleLead, femaleLead;
        int year;
        getline(ss, name, '#');
        getline(ss, genre, '#');
        getline(ss, director, '#');
        getline(ss, maleLead, '#');
        getline(ss, femaleLead, '#');
        ss >> year;

        movieList.addTail(Movie(name, genre, director, maleLead, femaleLead, year));
    }
    inFile.close();
}

int main() {
    LinkedList<Movie> movieList;

    readMoviesFromFile(movieList, "Input.txt");

    cout << "Movies before updating:" << endl;
    movieList.display();
    string movieName;
    string newGenre;
    cout << "Enter movie name to update genre: ";
    cin >> ws; 
    getline(cin, movieName);
    cout << "Enter new genre (criminal, romance, comedy): ";
    cin >> newGenre;

    movieList.updateGenre(movieName, newGenre);
    movieList.writeToFile("Input.txt"); 

    cout << "Movies after updating:" << endl;
    movieList.display();

    string actorName;
    cout << "Enter an actor's name: ";
    cin >> ws; 
    getline(cin, actorName);
    movieList.saveMoviesByActor(actorName);

    movieList.saveMoviesByDirector();

    movieList.saveLatestMovies("PhimMoi.txt");

    return 0;
}
