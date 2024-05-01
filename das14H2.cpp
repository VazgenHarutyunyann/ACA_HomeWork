#include <iostream> 
#include <string>

class GamePiece
{
private:
    std::string m_name;
public:
    GamePiece(const std::string& name) :
        m_name(name) {}

    virtual ~GamePiece()
    {

    }    

    virtual void move() = 0;
};

class Solider : public GamePiece
{
private:
    std::string m_color;

public:
    Solider(const std::string& color) : 
        GamePiece("Solider") , m_color(color) {}

    ~Solider()
    {

    }

    void move() override
    {
        std::cout << "Solider color is " << m_color << " and he is moving only Forward: " << std::endl;
    }
};

class Elephant : public GamePiece
{
private:
    std::string m_color;

public:
    Elephant(const std::string& color) :
        GamePiece("Elephant") , m_color(color) {}

    ~Elephant()
    {

    }

    void move() override
    {
        std::cout << "Elephant color is " << m_color << " and he is moving only by Diagonals: " << std::endl;
    }
};

class Horse : public GamePiece
{
private:
    std::string m_color;

public:
    Horse(const std::string& color) :
        GamePiece("Horse") , m_color(color) {}

    ~Horse()
    {

    }

    void move() override
    {
        std::cout << "Horse color is " << m_color << " and he is moving two steps Forward or Back and 1 step Right or Left: " << std::endl;
        std::cout << "Or he moving two steps Right or Left and 1 step Forward or Back: " << std::endl;
    } 
};

class Boat : public GamePiece
{
private:
    std::string m_color;

public:
    Boat(const std::string& color) :
        GamePiece("Boat") , m_color(color) {}

    ~Boat()
    {

    }

    void move() override
    {
        std::cout << "Boat color is " << m_color << " and he is moving Forward or Back or Right or Left: " << std::endl;
    }
};

class Queen : public GamePiece
{
private:
    std::string m_color;

public:
    Queen(const std::string& color) :
        GamePiece("Queen") , m_color(color) {}

    ~Queen()
    {

    }

    void move() override
    {
        std::cout << "Quenn color is " << m_color << " and she is moving Forward , Back , Left , Right or by Diagonals: " << std::endl;
    }

};

class King : public GamePiece
{
private:
    std::string m_color;

public:
    King(const std::string& color) :
        GamePiece("King") , m_color(color) {}

    ~King() 
    {

    }

    void move() override
    {
        std::cout << "King is most important game piece your color is " << m_color << " you need to safe him and he is moving aroud him: " << std::endl;
    }
};

void fillSoliders(GamePiece** arr)
{
    int k = 0;

    for (int i = 0; i < 8; ++i)
    {
        arr[k] = new Solider("White");
        arr[k + 1] = new Solider("Black");
        k = k + 2;
    }
    
}

void fillAnother(GamePiece** arr)
{
    int k = 16;
    for (int i = 0; i < 2; ++i)
    {
        arr[k] = new Elephant("White");
        arr[k + 1] = new Elephant("Black");
        arr[k + 2] = new Horse("White");
        arr[k + 3] = new Horse("Black");
        arr[k + 4] = new Boat("White");
        arr[k + 5] = new Boat("Black");
        if (i == 0)
        {
            arr[k + 6] = new Queen("White");
            arr[k + 7] = new King("White");
        }
        else
        {
            arr[k + 6] = new Queen("Black");
            arr[k + 7] = new King("Black"); 
        }

        k = k + 8;
        

    }
    
}

int main()
{

    const int size = 32;
    GamePiece** pieces = new GamePiece*[size];

    fillSoliders(pieces);
    fillAnother(pieces);

    for (int i = 0; i < size; ++i) 
    {
        std::cout << i + 1 << ")";
        pieces[i]->move();
    }

    for (int i = 0; i < size; ++i) 
    {
        delete pieces[i];
        pieces[i] = nullptr;
    }
    delete[] pieces;

    


    return 0;
}