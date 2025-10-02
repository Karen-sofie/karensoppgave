//inkludering av bibloteker
#include "threepp/threepp.hpp"
#include <math.h>
#include <vector>
#include <memory>
#include <random>
//lister
using namespace threepp;

struct BallKontroller :KeyListener {

    // Constructor: Takes a reference to our vector of spheres
    BallKontroller(std::vector<std::shared_ptr<Mesh>>& baller)
        : meshes(baller), selectedIndex(0) {
    }


        void onKeyPressed(KeyEvent evt) override {
        auto ball = meshes[selectedIndex];

        if (evt.key == Key::TAB){
            if (selectedIndex >= meshes.size() - 1) {
                selectedIndex = 0;
            } else {
                selectedIndex = selectedIndex + 1;
            }


        }
            if (evt.key == Key::UP) {
                ball->position.y+=0.1f;


            }
            if (evt.key == Key::DOWN) {
                ball->position.y-=0.1f;

            }
            if (evt.key == Key::LEFT) {
                ball->position.x+=0.1f;

            }
            if (evt.key == Key::RIGHT) {
                ball->position.x-=0.1f;

            }


        }




    private:
    //legg til en til variabel 
        std::shared_ptr<MeshBasicMaterial> math1{};
        std::shared_ptr<MeshBasicMaterial> math2{};
        int index = 0;
    std::shared_ptr<Mesh> baller;

    std::vector<std::shared_ptr<Mesh>>& meshes;
    int selectedIndex;

        // Random generator
        float randomFloat() {
            static std::random_device rd;
            static std::mt19937 gen(rd());
            static std::uniform_real_distribution<float> dist(0.0f, 1.0f);
            return dist(gen);
        }
    };



int main() {
    Canvas canvas;
    GLRenderer renderer(canvas.size());

    Scene scene; //et objeckt
    PerspectiveCamera camera(60, canvas.aspect(),0.1,1000);
    camera.position.z=5;
    auto LIKGEOMETRI = SphereGeometry::create(0.3);



    std::vector<std::shared_ptr<Mesh>> vectorName;


    auto hvordan_objekt_ser_ut1= MeshBasicMaterial::create();
    auto hvordan_objekt_ser_ut2= MeshBasicMaterial::create();
    hvordan_objekt_ser_ut1->color = Color::blue;
    hvordan_objekt_ser_ut2->color = Color::blue;
    for (int i= 0; i<8; i++) {
        std::shared_ptr<MeshBasicMaterial> matrial{};
        if (i%2==0) {
            matrial = hvordan_objekt_ser_ut1;

        }
        else  {
            matrial= hvordan_objekt_ser_ut2;
        }
        auto utsende_form = Mesh::create(LIKGEOMETRI, matrial);
        utsende_form->position.x = -4+i;
        vectorName.push_back(utsende_form);
        scene.add(utsende_form);
    }

    auto keyController = std::make_unique<BallKontroller>(vectorName);
    canvas.addKeyListener(*keyController);

    float count=0.0;
    canvas.animate([&] {
     renderer.render (scene,camera);
        //utsende_form->position.y=std::sin(count);

        }
);




    return 0;
}