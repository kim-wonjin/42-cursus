# 1. get_next_line

|  |  |
| :-: | - |
| Topic | Static Variables, File I/O |
| Related | Operating Systems |
| Stack | C |

<br/>

# 2. Summary

get_next_line 프로젝트는 파일 디스크립터로부터 텍스트를 읽고, 개행으로 끝나는 하나의 문자열을 반환하는 `get_next_line` 함수를 구현하는 것이다. 구현하는 함수의 프로토타입은 다음과 같다.

```c
int get_next_line(int file_descriptor, char **line);
```

 <br/>

# 3. What I learned

파일 디스크립터의 원리와 파일 입출력에 대해 학습하였으며, 정적변수의 활용을 숙달하였다. 
 <br/>

# 4. Features

* 구현한 `get_next_line` 함수는 파일 또는 표준입력으로부터 통해 텍스트를 읽고, 개행으로 구분되는 하나의 문자열을 반환한다. `EOF`에 도달하여 더이상 읽어올 것이 없으면 `0`을 반환한다. 에러가 발생하면 `-1`을 반환하며, 이때 모든 동적 할당 메모리는 해제된다.

* `get_next_line` 함수를 반복문 안에서 호출하면, 파일 디스크립터에 존재하는 텍스트를 `EOF` 전까지 한 번에 한 줄씩 읽어들일 수 있다.

* 개행 이후의 나머지 문자열은 정적변수에 의해 저장된다. 따라서 프로그램을 종료하거나 `EOF`에 도달하기 전에는 그 값이 유지된다.

* `get_next_line` 함수를 포함하는 프로그램은 다음과 같은 방법으로 컴파일 한다. `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <파일들>.c` 이때, `BUFFER_SIZE`를 지정하지 않으면 정의된 매크로 상수값에 따라 `1`로 지정된다.

* `get_next_line` 함수는 다중 파일 디스크립터를 처리할 수 있다. 즉, `get_next_line` 함수를 포함하는 프로그램은 다수의 파일이 열린 상태에서 각각의 파일에 대해 작업을 수행할 수 있다.

<br/>

# 5. How to call the function

```c
// This is just an example of reading lines in test.txt by opening it Read-Only.

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int fd;
	int ret_gnl;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	ret_gnl = get_next_line(fd, &line);
	while (ret_gnl == 1)
	{
		printf("Return: %d\n", ret_gnl);
		printf("Sring: %s\n", line);
		free(line);
		line = NULL;
		ret_gnl = get_next_line(fd, &line);
	}
	close(fd);
	if (ret_gnl == -1)
		return (1);
	return (0);
}
```

