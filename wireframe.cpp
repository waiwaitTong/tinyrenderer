#include "wireframe.h"
std::vector<Vertex> vertices;
std::vector<Face> faces;
void load_obj() {

    std::ifstream file("./obj/diablo3_pose/diablo3_pose.obj");
    std::string line;
    if (!file) {
        std::cerr << "Cannot open model file\n";
        return;
    }
    while(std::getline(file,line)){

    std::istringstream isstream(line);
    std::string type;
    isstream >> type;
    if(type == "v"){
        Vertex v;
        isstream >> v.x >> v.y >> v.z;
        vertices.push_back(v);
    }
    if(type == "f"){
        std::string a, b, c;
        if(isstream>>a>>b>>c){
            Face f;
            f.a = std::stoi(a)-1;
            f.b = std::stoi(b)-1;
            f.c = std::stoi(c)-1;
            faces.push_back(f);
        }

    }

    }
// std::cout << "Faces: " << faces.size() << '\n';
}

void line(int x0, int y0, int x1, int y1, TGAImage &image, const TGAColor &color){
    bool steep = false;
    if(std::abs(x0-x1)<std::abs(y0-y1)){
        std::swap(x0,y0);
        std::swap(x1,y1);
        steep = true;
    }
    if(x0>x1){
        std::swap(x0,x1);
        std::swap(y0,y1);
    }
    float y=y0;
    int delta_x = x1-x0;
    for(int x=x0; x<=x1; x++){
       
        if(steep){
            image.set(y,x,color);
        }else{
            image.set(x,y,color);
        }
         y+= (y1-y0)/(float)delta_x;
    }
}

