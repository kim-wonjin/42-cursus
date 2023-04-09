# 1. ft_printf

|  |  |
| :-: | - |
| Topic | Variadic Arguments, Parsing |
| Related | Computer Architecture |
| Stack | C |

<br/>

# 2. Summary

ft_printf 프로젝트는 `printf` 함수를 직접 구현하는 것이다. 구현하는 함수의 프로토타입은 다음과 같다.

```c
int ft_printf(const char *format);
```

<br/>

# 3. What I learned

가변함수(Variadic function)의 원리와 구현에 대해 학습하였다. 또한 복잡한 구문분석(Parsing)을 숙달하였다. 

<br/>

# 4. Features

* 구현한 `ft_printf` 함수의 사용법은  `<stdio.h>`의 `printf`와 동일하며, 가변인자를 통한 서식지정자 사용을 지원한다. 사용가능한 서식지정자는 다음과 같다.

|  |  |
| - | - |
| Flag | `-` `0` |
| Width | `<numbers>` `*`  |
| Precision | `.<numbers>` `.*` |
| Type | `c` `s` `p` `d` `i` `u` `x` `X` `%` |

* `ft_printf` 함수는 주어진 문자열을 출력하기 위해 동적 메모리 할당을 사용하지 않는다. 따라서 버퍼 관리 기능은 지원하지 않는다.

* 본 프로젝트 결과물은 `f`, `F`, `e`, `E`, `g`, `G` 옵션은 지원하지 않는다.

<br/>

# 5. How to compile the project

본 프로젝트의 결과물은 정적 라이브러리를 생성하는 `Makefile`을 포함한다. 해당 `Makefile`은 common rules(`all`, `clean`, `fclean`, `re`)와 `bonus` rule을 지원한다.
* For the Mandatory
> make all
* For the Bonus
> make bonus

<br/>

# 6. How to include the static library

외부 프로젝트에서, 본 프로젝트의 결과물인 정적 라이브러리를 활용하고자 할 때는 다음 명령어를 사용한다.

> gcc -Wall -Werror -Wextra -L \<directory-name> -l \<library-name>

정적 라이브러리의 이름은 `lib`로 시작해야 하며 `.a`로 끝나야 한다. 또한 \<library-name>은 `lib`와 `.a`를 제외한 형태이어야 한다. 정적 라이브러리 이름을 `libftprintf.a`로 한다면 \<library-name>은 `ftprintf`이어야 한다.
