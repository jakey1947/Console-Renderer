#include <complex>
namespace CustomTypes
{

  template <typename T> float sgn(T val) {
      return (T(0) < val) - (val < T(0));
  }

    struct Vector2
    {
        public:
        float x, y;

        Vector2(float x = 0, float y = 0) : x{x}, y{y} {}

        
        float GetMaximum()
        {
            return x > y ? x : y;
        }

        Vector2 abs()
        {
            return Vector2(std::abs(x), std::abs(y));
        }

        float Magnitude()
        {
            return x+y;
        }

        Vector2 Normalize()
        {
            return Vector2(x,y) / Magnitude();
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

        Vector2 operator*(float r)
        {
            return Vector2(x * r, y * r);
        }

        Vector2 operator/(float r)
        {
            return Vector2(x / r, y / r);
        }

        Vector2 operator+=(const Vector2& r){
            return Vector2(x += r.x, y += r.y);
        }

        Vector2 operator-=(const Vector2& r){
            return Vector2(x -= r.x, y -= r.y);
        }

        Vector2 operator*=(const Vector2& r){
            return Vector2(x *= r.x, y *= r.y);
        }

        Vector2 operator/=(const Vector2& r){
            return Vector2(x /= r.x, y /= r.y);
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

        //   //Vector2 , float comparisons
        //   inline bool operator==(float r)
        //   {
        //       return (x == r && y == r);
        //   }

        //   inline bool operator!=(float r){
        //     return !(this == r);
        //   }
        //   inline bool operator<(float r)
        //   {
        //       return x < r || y < r;
        //   }
        //   inline bool operator>(float r)
        //   {
        //       return r < l;
        //   }
        //   inline bool operator>=(float r)
        //   {
        //       return !(this < r);
        //   }

        //   inline bool operator<=(float r)
        //   {
        //       return !(r < this);
        //   }

        #pragma endregion
        
    };      
}