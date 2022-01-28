struct line{
    point p;
    point vel;

    line(point& _p, point& _vel){
        p = _p;
        vel = _vel;
    }


    point intersection(line& l){
        double a1 = -1 * vel.y;
        double b1 = vel.x;
        double c1 = -1 * p.y * vel.x + p.x * vel.y; 
        double a2 = -1 * l.vel.y;
        double b2 = l.vel.x;
        double c2 = -1 * l.p.y * l.vel.x + l.p.x * l.vel.y; 
        double x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
        double y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);
        point r(x,y);
        return r;
    }

    point closestToPoint(point& op){
        point perpVel(vel.y, -1 * vel.x);
        line l(op, perpVel);
        return intersection(l);
    }
};

line from2Points(point& to, point& from){
    point v(to.x - from.x, to.y - from.y);
    line r(to, v);
    return r;
}
