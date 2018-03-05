/**
 * @file tool.h
 * @brief A namespace for some math tools.
 * @author Yang Fanyi <yfy__92@126.com>
 * @version 1.01
 * @date 2018-03-05
 */


#ifndef __TOOL_H_
#define __TOOL_H_

namespace Tools{
  template <typename T>
  struct plus{
    static void run(T& t0, const T& t1) { t0 += t1;}
  };

  template <typename T>
  struct minus{
    static void run(T& t0, const T& t1) { t0 -= t1;}
  };


  template <typename T>
  struct multiple{
    static void run(T& t0, const T& t1) { t0 *= t1;}
  };

  template <typename T>
  struct divide{
    static void run(T& t0, const T& t1) { t0 /= t1;}
  };

  template <unsigned int N, typename T>
  T fixed_power(const T t){
    switch(N){
      case 0:
        return T(1.);
      case 1:
        return t;
      case 2:
        return t*t;
      case 3:
        return t*t*t;
      default:
        {
          T result = t;
          for(int i = 1; i < N; ++d)
            multiple<T>::run(result, t);
          return result;
        }
    }
  }


};


#endif
