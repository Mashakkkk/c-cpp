#include <SFML/Graphics.hpp>

class Point { // создаем абстрактный класс
public:
    virtual void draw(sf::RenderWindow& window) = 0; 
    virtual void move(float dx, float dy) = 0; 
    virtual void rotate(float angle) = 0; 
    virtual ~Point() = default; // виртуальный деструктор
};

class Rectangle : public Point { // создаем класс rectangle, наследованный от класса point
    sf::RectangleShape rectangle;
public:
    Rectangle(float x, float y, float w, float h, sf::Color color) { // конструктор
        rectangle.setSize({ w, h }); // ширина, высота
        rectangle.setPosition(x, y); // откуда отсчет
        rectangle.setFillColor(color); // цвет
        rectangle.setOrigin(w / 2, h / 2); // центр фигуры
    }
    void draw(sf::RenderWindow& window) { //функция для отображения фигуры в окне
        window.draw(rectangle);
    }
    void move(float dx, float dy) {
        rectangle.move(dx, dy);
    }
    void rotate(float angle) {
        rectangle.rotate(angle);
    }
    sf::Vector2f getPosition() {
        return rectangle.getPosition(); // возвращаем текущую позицию
    }
};

class Square : public Rectangle { // квадрат, наследованный от прямоугольника
public:
    Square(float x, float y, float z, sf::Color color) // z-сторона квадрата
        : Rectangle(x, y, z, z, color) {
    }
};

class Rhomb : public Point {
    sf::ConvexShape rhomb;
    float center_x, center_y;
    float rotation = 0;
public:
    Rhomb(float x, float y, float d1, float d2, sf::Color color) : center_x(x), center_y(y) {
        rhomb.setPointCount(4); // указываем количество точек, из которых будет состоять фигура
        rhomb.setPoint(0, sf::Vector2f(0, -d2 / 2)); // верхнаяя точка
        rhomb.setPoint(1, sf::Vector2f(d1 / 2, 0)); // правая точка
        rhomb.setPoint(2, sf::Vector2f(0, d2 / 2)); // нижняя точка
        rhomb.setPoint(3, sf::Vector2f(-d1 / 2, 0)); // левая точка
        rhomb.setFillColor(color);
        rhomb.setOrigin(0, 0); // фигура появляется из начала координат
        updatePosition(); // обновляем расположение
    }
    void updatePosition() {
        rhomb.setPosition(center_x, center_y); // устанавливаем позицию
        rhomb.setRotation(rotation);
    }
    void draw(sf::RenderWindow& window) {
        window.draw(rhomb);
    }
    void move(float dx, float dy) {
        center_x += dx;
        center_y += dy;
        updatePosition();
    }
    void rotate(float angle) {
        rotation += angle;
        updatePosition();
    }
    sf::Vector2f getPosition() {
        return { center_x, center_y };
    }
};

class Parallelogram : public Point {
    sf::ConvexShape parall; 
    float center_x, center_y;
    float rotation = 0;
public:
    Parallelogram(float x, float y, float d, float h, float shift, sf::Color color): center_x(x), center_y(y) { // присваиваем центру x и y значения x и y соответсвенно
        parall.setPointCount(4);
        parall.setPoint(0, sf::Vector2f(-d / 2 + shift, -h / 2)); // составляем фигуру с учетом смещения
        parall.setPoint(1, sf::Vector2f(d / 2 + shift, -h / 2));
        parall.setPoint(2, sf::Vector2f(d / 2 - shift, h / 2));
        parall.setPoint(3, sf::Vector2f(-d / 2 - shift, h / 2));
        parall.setFillColor(color);
        parall.setOrigin(0, 0);
        updatePosition();
    }
    void updatePosition() {
        parall.setPosition(center_x, center_y);
        parall.setRotation(rotation);
    }
    void draw(sf::RenderWindow& window) {
        window.draw(parall);
    }
    void move(float dx, float dy) {
        center_x += dx;
        center_y += dy;
        updatePosition();
    }
    void rotate(float angle) {
        rotation += angle;
        updatePosition();
    }
    sf::Vector2f getPosition() {
        return { center_x, center_y };
    }
};

class Line : public Point {
    sf::Vertex line[2]; // массив из двух точек
    float rotation = 0;
    sf::Vector2f center; // центр отрезка
public:
    Line(float x1, float y1, float x2, float y2, sf::Color color) {
        line[0] = sf::Vertex(sf::Vector2f(x1, y1), color); 
        line[1] = sf::Vertex(sf::Vector2f(x2, y2), color);
        center = { (x1 + x2) / 2, (y1 + y2) / 2 }; 
    }
    void draw(sf::RenderWindow& window) {
        window.draw(line, 2, sf::Lines); 
    }
    void move(float dx, float dy) { 
        line[0].position.x += dx;
        line[0].position.y += dy;
        line[1].position.x += dx;
        line[1].position.y += dy;
        center.x += dx;
        center.y += dy;
    }
    void rotate(float angle) {
        rotation += angle;
            for (int i = 0; i < 2; ++i) { // для первой и второй точки
                sf::Vector2f p = line[i].position; // координаты точки
                float s = sin(angle * 3.14 / 180); // синус угла в радианах
                float c = cos(angle * 3.14 / 180);
                p.x -= center.x; 
                p.y -= center.y;
                float xnew = p.x * c - p.y * s; // поворот
                float ynew = p.x * s + p.y * c;
                line[i].position.x = center.x + xnew; 
                line[i].position.y = center.y + ynew;
            }
    }
    sf::Vector2f getPosition() {
        return center;
    }
};

class Pointt : public Point {
    sf::CircleShape point; // точка - окружность с маленьким радиусом
public:
    Pointt(float x, float y, sf::Color color) {
        point.setRadius(4);
        point.setFillColor(color);
        point.setPosition(x, y);
    }
    void draw(sf::RenderWindow& window) {
        window.draw(point);
    }
    void move(float dx, float dy) {
        point.move(dx, dy);
    }
    void rotate(float /*angle*/) {
    }
    sf::Vector2f getPosition() {
        return point.getPosition();
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(900, 700), "Windoooooooow"); // настройка окна 

    Point* shapes[6]; // указатель на фигуру
    shapes[0] = new Rectangle(100, 200, 200, 100, sf::Color::White);
    shapes[1] = new Square(500, 50, 80, sf::Color::Cyan);
    shapes[2] = new Pointt(500, 500, sf::Color::White);
    shapes[3] = new Rhomb(700, 550, 140, 120, sf::Color::Cyan);
    shapes[4] = new Parallelogram(200, 550, 180, 120, 30, sf::Color::White);
    shapes[5] = new Line(10, 10, 150, 150, sf::Color::Cyan);

    float speedX = 20; // скорость по иксу
    float speedY = 20; 
    float rotateSpeed = 180; 

    sf::Clock clock; // время

    while (window.isOpen()) { 
        sf::Event event;
        while (window.pollEvent(event)) 
            if (event.type == sf::Event::Closed)
                window.close();

        float dt = clock.restart().asSeconds(); // время, прошедшее с последнего действия в окне

        for (int i = 0; i < 6; i++) { // новый показ фигур
            shapes[i]->move(speedX * dt, speedY * dt); // перемещаем
            shapes[i]->rotate(rotateSpeed * dt); // поворачиваем

            sf::Vector2f pos; // текущая позиция текущей фигуры
            if (auto rectangle = dynamic_cast<Rectangle*>(shapes[i])) pos = rectangle->getPosition();
            else if (auto square = dynamic_cast<Square*>(shapes[i])) pos = square->getPosition();
            else if (auto rhomb = dynamic_cast<Rhomb*>(shapes[i])) pos = rhomb->getPosition();
            else if (auto parall = dynamic_cast<Parallelogram*>(shapes[i])) pos = parall->getPosition();
            else if (auto line = dynamic_cast<Line*>(shapes[i])) pos = line->getPosition();
            else if (auto point = dynamic_cast<Pointt*>(shapes[i])) pos = point->getPosition();
            else pos = { 0, 0 };

            if (pos.x > 900) shapes[i]->move(-900, 0); // возвращаемся влево при выходе за правую границу
            if (pos.y > 700) shapes[i]->move(0, -700); // возвращаемся вверх при выходе за нижнюю границу
        }

        window.clear(); // очистка
        for (int i = 0; i < 6; i++) // рисуем
            shapes[i]->draw(window);
        window.display(); // отображаем
    }

    for (int i = 0; i < 6; i++) // освобождаем память
        delete shapes[i];

    return 0;
}