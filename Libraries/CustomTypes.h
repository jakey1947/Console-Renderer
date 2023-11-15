namespace CustomTypes
{

  template <typename T> int sgn(T val) {
      return (T(0) < val) - (val < T(0));
  }

  struct Vector2
  {
    int x, y;

    Vector2(int x, int y){};
    Vector2(){};
    
    int GetMaximum(){return int();};
    #pragma region operators
    Vector2 operator+(Vector2 other){return Vector2();};

    Vector2 operator-(Vector2 other){return Vector2();};

    Vector2 operator*(Vector2 other){return Vector2();};

    Vector2 operator/(Vector2 other){return Vector2();};

    Vector2 operator*(int other){return Vector2();};

    Vector2 operator/(int other){return Vector2();};

    bool operator==(Vector2 other){return true;};

    bool operator!=(Vector2 other){return true;};

    bool operator<(Vector2 other){return true;};
    bool operator>(Vector2 other){return true;};
    bool operator<=(Vector2 other){return true;};
    bool operator>=(Vector2 other){return true;};

        //Vector2 , int comparisons
    bool operator==(int r){return true;};
    bool operator!=(int r){return true;};
    bool operator<(int r){return true;};
    bool operator>(int r){return true;};
    bool operator>=(int r){return true;};
    bool operator<=(int r){return true;};
    #pragma endregion
    
    };  
}