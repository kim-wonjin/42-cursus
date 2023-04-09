# 1. push_swap

|  |  |
| :-: | - |
| Topic | Complexity, Sorting Algorithms |
| Related | Data Structures, Algorithms & Analysis |
| Stack | C |

<br/>

# 2. Summary

push_swap 프로젝트는 정렬 알고리즘을 활용하여, 스택의 모든 원소를 오름차순으로 정렬하는 프로그램을 구현하는 것이다. 제한된 명령어 집합을 가능한 적게 사용하기 위해 알고리즘을 조작하고 최적화된 솔루션을 고안해야 한다.

<br/>

# 3. What I learned

알고리즘과 시간복잡도의 개념에 대해 학습하였다. 또한, 대표적인 정렬 알고리즘인 빠른정렬의 구현과 최적화에 대해 숙달하였다. 

<br/>

# 4. Features

* `push_swap` 프로그램은 정렬하고자 하는 여러개의 숫자를 인자로 받고 하나의 스택(A)에 저장한다.

* 숫자 인자들은 두개의 스택(A, B)을 적절히 이동하며 정렬된다.

* 숫자 인자들은 다음의 11개의 명령어에 의해서만 이동될 수 있다.

```
	pb : Pushing top of the 1 element from A to B
	pa : Pushing top of the 1 element from B to A
	ra : Rotating A with ccw
	rb : Rotating B with ccw
	rr : Rotating both with ccw
	rra : Rotating A with cw
	rrb : Rotating B with cw
	rrr : Rotating both with cw
	sa : Swapping top of the 2 elements on A
	sb : Swapping top of the 2 elements on B
	ss : Swapping top of the 2 elements on both
```

* `push_swap` 프로그램 작동중 오류 발생 시 `Error\n`를 출력한다.

* 본 프로젝트에서 직접 구현한 정렬 알고리즘의 기대값은 `3/5 * log n / log 3`이며, 500개의 숫자 인자들을 정렬하는데 대략 4500회의 명령어가 소요된다.

<br/>

# 5. How to compile the project
본 프로젝트의 결과물은 `Makefile`을 포함한다. 해당 `Makefile`은 common rules(`all`, `clean`, `fclean`, `re`)와 `bonus` rule을 지원한다. 모든 소스코드들이 컴파일된 후에 프로그램이 생성된다.

* For the Mandatory
> make all
* For the Bonus
> make bonus

<br/>

# 6. How to execute the program

`push_swap` 프로그램은 정렬하고자 하는 여러개의 숫자를 인자로 받는다.

> ./push_swap \<numeric-arguments>

실행 결과는 인자를 정렬하기 위한 최소한의 명령 집합이다.

`checker` 또한 `push_swap`에 사용된 여러개의 숫자를 인자로 받는다. 한편 `checker`는 `push_swap`의 실행결과인 명령어의 집합을 기준으로 채점을 실시한다. 이때 명령어는 `|` 또는 표준입력을 통해 입력할 수 있다. 표준입력을 통해 명령어를 입력할때는 `ctrl + D`를 통해 전송을 완료할 수 있다.

> ./checker \<numeric-arguments>

> ./push_swap \<numeric_arguments> | ./checker \<numeric-arguments>

> ARG=\<numeric-arguments> ; ./push_swap $ARG | ./checker $ARG
