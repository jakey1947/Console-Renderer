namespace CustomTypes
{

  template <typename T> int sgn(T val) {
      return (T(0) < val) - (val < T(0));
  }

    struct Vector2
    {
        public:
        int x, y;

        Vector2(int x = 0, int y = 0) : x{x}, y{y} {}

        
          int GetMaximum()
        {
            return x > y ? x : y;
        }

        #pragma region Operators
        Vector2 operator+(const Vector2& r){
            return Vector2(x + r.x, y + r.y);
        }

        Vector2 operator-(const Vector2& r){
            return Vector2(x - r.x, y - r.y);
        }

        Vector2 operator*(const Vector2& r){
            return Vector2(x * r.x, y * r.y);
        }

        Vector2 operator/(const Vector2& r){
            return Vector2(x / r.x, y / r.y);
        }

        Vector2 operator*(int r)
        {
            return Vector2(x * r, y * r);
        }

        Vector2 operator/(int r)
        {
            return Vector2(x / r, y / r);
        }

        inline bool operator==(const Vector2& r)
        {
            return (x == r.x && y == r.y);
        }

        inline bool operator!=(const Vector2& r){
            return !(this == &r);
        }
        inline bool operator<(const Vector2& r)
        {
            return x < r.x || y < r.y;
        }
        inline bool operator>(const Vector2& r)
        {
            return &r < this;
        }
        inline bool operator>=(const Vector2& r)
        {
            return !(this < &r);
        }
        inline bool operator<=(const Vector2& r)
        {
            return !(&r < this);
        }

        //   //Vector2 , int comparisons
        //   inline bool operator==(int r)
        //   {
        //       return (x == r && y == r);
        //   }

        //   inline bool operator!=(int r){
        //     return !(this == r);
        //   }
        //   inline bool operator<(int r)
        //   {
        //       return x < r || y < r;
        //   }
        //   inline bool operator>(int r)
        //   {
        //       return r < l;
        //   }
        //   inline bool operator>=(int r)
        //   {
        //       return !(this < r);
        //   }

        //   inline bool operator<=(int r)
        //   {
        //       return !(r < this);
        //   }

        #pragma endregion
        
    };      
}