#include <stdio.h>
#include <unistd.h>

void printPid();

int main(int argc, char **argv)
{
    printf("[%d] I am the root parent\n", getpid());
    pid_t leftChild = fork();
    if (leftChild == 0)
    {
        printf("[%d] My parent is [%d]\n", getpid(), getppid());
    }
    else
    {
        pid_t rightChild = fork();
        if (rightChild == 0)
        {
            printf("[%d] My parent is [%d]\n", getpid(), getppid());
            pid_t leftGrandchild = fork();
            if (leftGrandchild == 0)
                printf("[%d] My parent is [%d]\n", getpid(), getppid());
            else
            {
                pid_t rightGrandchild = fork();
                if (rightGrandchild == 0)
                    printPid();
            }
        }
    }
    return 0;
}

void printPid() { printf("[%d] My parent is [%d]\n", getpid(), getppid()); }
