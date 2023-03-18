#include <iostream>
#include <cmath>


const double PI = acos(-1.0);
using namespace std;


template <typename N, typename M>
struct Pair{

    N first;

    M second;

};


double triangle_square(Pair <double, double> p1, Pair <double, double> p2, Pair <double, double> p3){
    return abs( ( (p2.first - p1.first) * (p3.second - p1.second) ) - ( (p3.first - p1.first) * (p2.second - p1.second) ) ) / 2;
}


double minor_squares(Pair <double, double> points[], int size){
    if ( size < 3 ) {return 0;}
    int index_p1 = 0;
    int index_p2 = size - 1;
    int index_p3 = (index_p2 - (index_p2 % 2)) / 2;
    double square = triangle_square(points[index_p1], points[index_p2], points[index_p3]);
    int size_1 = index_p3 - 1;
    int size_2 = index_p2 - index_p3 - 1;
    Pair <double, double> triangle_1[size_1];
    Pair <double, double> triangle_2[size_2];

    for ( int i = 1; i < index_p3; i++ ){
        triangle_1[i - 1] = points[i];
    }

    for ( int i = index_p3 + 1; i < size - 2; i++ ){
        triangle_2[i - index_p3 - 1] = points[i];
    }

    return square + minor_squares(triangle_1, size_1) + minor_squares(triangle_2, size_2);
}


double major_square(int n, Pair <double, double> points[]){

    int index_p1 = 0;
    int index_p2;
    int index_p3;

    if ( n % 3 == 0){
        index_p2 = n / 3;
        index_p3 = 2 * ( n / 3 );
    }

    else if ( n % 3 == 1 ){
        index_p2 = (n - 1) / 3;
        index_p3 = 2 * ( (n - 1) / 3 );
    }

    else if ( n % 3 == 2 ){
        index_p2 = (n - 2) / 3 + 1;
        index_p3 = 2 * ( (n - 2) / 3 + 1 );
    }

    double square = triangle_square(points[index_p1], points[index_p2], points[index_p3]);
    int size_1 = index_p2 - index_p1 - 1;
    int size_2 = index_p3 - index_p2 - 1;
    int size_3 = n - size_1 - size_2 - 3;
    Pair <double, double> triangle_1[size_1];
    Pair <double, double> triangle_2[size_2];
    Pair <double, double> triangle_3[size_3];

    for ( int i = 1; i < index_p2; i++ ){
        triangle_1[i - 1] = points[i];
    }

    for ( int i = index_p2 + 1; i < index_p3; i++ ){
        triangle_2[i - index_p2 - 1] = points[i];
    }

    for ( int i = index_p3 + 1; i < n; i++ ){
        triangle_3[i - index_p3 - 1] = points[i];
    }

    return square + minor_squares(triangle_1, size_1) + minor_squares(triangle_2, size_2) + minor_squares(triangle_3, size_3);
}


int main(){
    int n;
    cin >> n;
    double R = 1 / ( 2 * sin(PI / n) );
    Pair <double, double> points[n];

    for ( int i = 0; i < n; i++ ){
        points[i].first = R * cos( (2 * PI * i) / n );
        points[i].second = R * sin( (2 * PI * i) / n );
    }

    double square = major_square(n , points);
    double pidor_square = (n/2) * R * R * sin(2 * PI/n);   
    cout.precision(7);
    cout << major_square(n , points) << "\n";
    return 0;

}