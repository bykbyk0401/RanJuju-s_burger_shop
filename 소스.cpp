#include <bangtal.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

// Ŭ����
class Ingredient {
private:

public:
    ObjectID obj_Ingredient;
};

class Burger {
private:

public:
    ObjectID obj_Burger;
};

class Side {
private:

public:
    ObjectID obj_Side;
};

class Drink {
private:

public:
    ObjectID obj_Drink;
};

class Customer {
private:

public:
    ObjectID obj_Customer;
};

class User {
private:
    map<string, int> ingredientSet;
    int myMoney; //���� ������ �ִ� ��


public:

    User(int initialMoney) : myMoney(initialMoney) {
        // Initialize the ingredientSet
        ingredientSet = {
            { "bread", 500 },
            { "bulgogiPatty", 1000 },
            { "chicken", 1000 },
            { "crabMeat", 2000 },
            { "cow", 10000 },
            { "tomato", 500 },
            { "cabbage", 500 },
            { "slicedCheese", 500 },
            { "potato", 500 },
            { "oil", 500 },
            { "stringCheese", 500 },
            { "coke", 1000 },
            { "soda", 1000 }
        };
    }

    void setMoney(int initialMoney) {
        myMoney = initialMoney;
    }

    // ���Ͽ��� �� ��Ḧ ��� ��Ͽ� �߰�
    void updateIngredients(const string& ingredient, int quantity) {
        if (ingredientSet.find(ingredient) != ingredientSet.end()) {
            ingredientSet[ingredient] += quantity;
        }
        else {
            ingredientSet.insert({ ingredient, quantity });
        }
    }

    // ���Ͽ��� ������ �� ���� ����
    void useMoney(int totalPrice) {
        if (myMoney >= totalPrice) {
            myMoney -= totalPrice;
            cout << "Money used: " << totalPrice << endl;
        }
        else {
            cout << "Insufficient funds!" << endl;
        }
    }

    // �մԿ��� �Ǹ��Ͽ� �� ����
    void earnMoney(int earnTotalPrice) {
        myMoney += earnTotalPrice;
        cout << "Money earned: " << earnTotalPrice << endl;
    }

    // ��Ḧ ����Ͽ� �ܹ��� �����
    void makeBurgerIngredients(const string& ingredient) {
        if (ingredientSet.find(ingredient) != ingredientSet.end() && ingredientSet[ingredient] > 0) {
            ingredientSet[ingredient]--;
        }
        else {
            cout << "Lack of ingredients!" << endl;
        }
    }

};



class Market {
private:
    Ingredient ingredient[13]; // 13��
public:
    Market() {
        ingredient[0].obj_Ingredient = createObject("bread", "Images/��.png", MarketScene, 430, 570);
        scaleObject(ingredient[0].obj_Ingredient, 0.045f);
        ingredient[1].obj_Ingredient = createObject("�Ұ����Ƽ", "Images/�Ұ����Ƽ.png", MarketScene, 430, 430);
        scaleObject(ingredient[1].obj_Ingredient, 0.065f);
        ingredient[2].obj_Ingredient = createObject("ġŲ", "Images/����.png", MarketScene, 420, 290);
        scaleObject(ingredient[2].obj_Ingredient, 0.06f);
        ingredient[3].obj_Ingredient = createObject("�Ի�", "Images/�Ի�.png", MarketScene, 430, 185);
        scaleObject(ingredient[3].obj_Ingredient, 0.2f);
        ingredient[4].obj_Ingredient = createObject("���Ѹ���", "Images/���Ѹ���.png", MarketScene, 430, 40);
        scaleObject(ingredient[4].obj_Ingredient, 0.07f);
        ingredient[5].obj_Ingredient = createObject("�丶��", "Images/�丶��.png", MarketScene, 710, 570);
        scaleObject(ingredient[5].obj_Ingredient, 0.065f);
        ingredient[6].obj_Ingredient = createObject("�����", "Images/�����.png", MarketScene, 705, 420);
        scaleObject(ingredient[6].obj_Ingredient, 0.04f);
        ingredient[7].obj_Ingredient = createObject("ü��ġ��", "Images/ü��ġ��.png", MarketScene, 710, 290);
        scaleObject(ingredient[7].obj_Ingredient, 0.065f);
        ingredient[8].obj_Ingredient = createObject("����", "Images/����.png", MarketScene, 710, 165);
        scaleObject(ingredient[8].obj_Ingredient, 0.1f);
        ingredient[9].obj_Ingredient = createObject("�Ŀ���", "Images/�Ŀ���.png", MarketScene, 990, 570);
        scaleObject(ingredient[9].obj_Ingredient, 0.1f);
        ingredient[10].obj_Ingredient = createObject("��Ʈ��ġ��", "Images/��Ʈ��ġ��.png", MarketScene, 990, 440);
        scaleObject(ingredient[10].obj_Ingredient, 0.2f);
        ingredient[11].obj_Ingredient = createObject("�ݶ�1ĵ", "Images/�ݶ�.png", MarketScene, 990, 300);
        scaleObject(ingredient[11].obj_Ingredient, 0.15f);
        ingredient[12].obj_Ingredient = createObject("���̴�1ĵ", "Images/���̴�.png", MarketScene, 990, 165);
        scaleObject(ingredient[12].obj_Ingredient, 0.185f);
    }

    bool chooseIngredients(ObjectID object) {
        for (int i = 0; i < 13; i++) {
            if (object == ingredient[i].obj_Ingredient) { // market scene���� ������ ��ǰ�� �������� ��
                // ******** ���� �����ϸ� �Ұ����ϴٰ� ���ؾ��� ********

                // ******** ���� �������� ������ ���� ������ �ִ� ���� ���̰� ������ �ִ� ��ǰ�� �߰�
            }
        }
    }
};

// ���� ����
int day = 0; // �� ��° ������
int customer_order = 1; // �� ��° �մ�����

SceneID StartScene, TutorialScene, MarketScene, BurgerScene, EndScene;
ObjectID TutorialButton, startButton; // StartScene
ObjectID closeButton; // TutorialScene
ObjectID completeButton; // MarketScene
ObjectID checkButton; // BurgerScene
ObjectID endButton; // EndScene

// �̺κ� �������� �Ű� ����
Burger burger[5]; // 5��
Side side[4]; // NULL ���� 4��
Drink drink[3]; // NULL ���� 3��
Customer customer[4]; // 5�ϸ��� �� 4��, �� �ٲ� ������ �ʱ�ȭ�ؼ� ����
User user;
Market market;

// �Լ� ���
void mouseCallback(ObjectID, int, int, MouseAction);
ObjectID createObject(const char*, const char*, SceneID, int, int);

// �Լ� ����
void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
    if (object == TutorialButton) { // Ʃ�丮�� ��ư�� ������
        enterScene(TutorialScene); // Ʃ�丮�� scene���� �̵�
    }
    else if (object == startButton) { // ���� ��ư�� ������
        enterScene(MarketScene); // ���� scene���� �̵�
    }
    else if (object == closeButton) { // Ʃ�丮���� �� �а� �ݱ� ��ư�� ������
        enterScene(StartScene); // ���� scene���� �̵�
    }
    else if (object == completeButton) { // ���Ÿ� ��ģ �� �Ϸ� ��ư�� ������
        // ********** ������ �ʱ�ȭ ********** -> �̶� object ����

        enterScene(BurgerScene); // �Ǹ� scene���� �̵�
    }
    else if (object == checkButton) { // �� �մԿ��� �޴��� �����ϱ� ���� üũ ��ư�� ������
        // ********* ��� �����ֱ� ************

        if (customer_order < 5) { // ������ �մ��� �ƴϸ�
            customer_order += 1; // ���� �մ��� ���� ��
        }
        else if (customer_order == 5) { // ������ �մ��̸�
            if (day < 5) { // ������ ���� �ƴϸ�
                customer_order = 1; // �մ� ���� �ʱ�ȭ
                day += 1; // �ش� ���� ������ ���� ���� �ٲ�
                enterScene(MarketScene); // ���� scene���� �̵�
            }
            else { // ������ ���̸�
                enterScene(EndScene);
            }
        }
    }
    else if (object == endButton) { // ���� ��ư�� ������
        endGame(); // ���� ����
    }
    else if (market.chooseIngredients(object) == true) {
        // ������ ingredients�� Ŭ���� ���
    }
}

ObjectID createObject(const char* name, const char* image, SceneID scene, int x, int y) {
    // object ���� �Լ�
    ObjectID object = createObject(image);
    locateObject(object, scene, x, y); // �ش� ��ġ�� object�� ��ġ��Ŵ
    showObject(object); // object�� ���̰� ��

    return object;
}

int main()
{
    // �� ������ �� �͵� ����
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

    setMouseCallback(mouseCallback);

    // scene ����
    // �� ������ �Է��ؾ� ��
    StartScene = createScene("StartScene", "");
    TutorialScene = createScene("TutorialScene", "");
    MarketScene = createScene("MarketScene", "");
    BurgerScene = createScene("BurgerScene", "");
    EndScene = createScene("EndScene", "");

    // object ����
    // ���� �̹���, ��ġ ���� ����
    TutorialButton = createObject("TutorialButton", "", StartScene, 0, 0);
    startButton = createObject("startButton", "", StartScene, 0, 0);
    closeButton = createObject("closeButton", "", TutorialScene, 0, 0);
    completeButton = createObject("completeButton", "", MarketScene, 0, 0);
    checkButton = createObject("checkButton", "", BurgerScene, 0, 0);
    endButton = createObject("endButton", "", EndScene, 0, 0);





    startGame(StartScene);
}