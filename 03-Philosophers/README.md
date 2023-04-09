# 1. Philosophers

|   |   |
| :-: | - |
| Topic | Synchronization, Mutex, Semaphore |
| Related | Operating Systems |
| Stack | C |


<br/>

# 2. Summary

Philosophers 프로젝트는 동시성 프로그래밍을 활용하여, 운영체제의 교착(deadlock)상태를 설명하기 위해 고안된 'Dining philosophers problem'을 해결하는 프로그램을 작성하는 것이다.

<br/>

# 3. What I learned

프로세스와 스레드의 개념, 운영체제와 스레드의 작동원리, 동기화, 뮤텍스와 세마포어에 대해 학습하였다. 또한 동시성 프로그래밍을 경험하고 `pthread`, `semaphore` 함수들에 대해 숙달하였다. 본 프로젝트에 대한 세부정보와 선행지식은 [Link](https://one-zin.tistory.com/14)에 정리하였다.

<br/>

# 4. Features

* 상기 문제를 mutex, semaphore를 활용하여 두 가지 방법으로 해결한다.
* `pthread_create` 혹은 `fork`에 의해 다수의 branch로 분기하며, main stream은 mutex 혹은 semaphore에 의해 대기 상태를 유지한다. 분기된 branch의 일련의 작업이 완료되면 main stream의 작업이 재개된다.
* branch가 분기되면 각 branch(철학자)는 자신의 죽음을 감시하는 monitoring thread를 전개한다.
* 이후 각 branch(철학자)는 Taking Fork, Eating, Putting Fork Down, Sleeping, Thinking을 반복(출력) 한다.
* 철학자의 상태변화를 출력하고자 할 때, 각 branch는 `pthread_mutex_lock` 혹은 `sem_wait`를 활용하여 printing resource에 대한 lock을 획득하고 반환하는 절차를 거친다.
* 각 branch의 시간을 동기화하기 위해, main stream에서 branch의 분기 직전 시간을 기록한다.
* 특정 철학자가 일정시간 동안 식사를 하지 못하면(starvation), 시뮬레이션은 실패로 종료된다.
* 오류 발생 시 `pthread_mutex_unlock` 혹은 `sem_post`가 호출되어 main stream의 작업이 재개되어 오류를 처리한다.

<br/>

# 5. How to compile the project

본 프로젝트의 결과물은 `Makefile`을 포함한다. 해당 `Makefile`은 common rules(`all`, `clean`, `fclean`, `re`)를 지원한다. 모든 소스코드들이 컴파일된 후에 프로그램이 생성된다.

* For both philo and philo_bonus

> make all

<br/>

# 6. How to execute the program

`pholo`와 `philo_bonus` 프로그램은 다음과 같은 인자를 받아 실행된다. 마지막 인자는 optional 하다.

* For the Medatory

> philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

* For the Bonus

> Philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
