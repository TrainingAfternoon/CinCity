class point{
    double x, y;

    point(){
        x = 0;
        y = 0;
    }

    point(double _x, double _y){
        x = _x;
        y = _y;
    }

    friend istream &operator>>( istream& input, point& P){
        input>>P.x>>P.y;
        return input;
    }

    friend ostream &operator<<( ostream& output, point& P){
        output<<"("<<P.x<<","<<P.y<<")";
        return output;
    }

    double dist(point& p){
        return sqrt(pow(p.x-x, 2) + pow(p.y-y, 2));
    }
    
    point operator-(point& p){
        point newPoint(x - p.x, y - p.y);
        return newPoint;
    }

    double magnitude(){
        return sqrt(x * x + y * y);
    }

    double dot(point& p){
        return x * p.x + y * p.y;
    }

    double cross(point& p){
        return x * p.y - y * p.x;
    }
}
