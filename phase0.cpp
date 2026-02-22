#include <iostream>

class Stack
{
public:
    Stack(int size) : stack{new int[size]}, m_size{size} {};
    Stack() : stack{new int[DEFAULT_SIZE]}, m_size{DEFAULT_SIZE} {};
    ~Stack()
    {
        delete[] stack;
    }
    Stack(const Stack &src) : m_size{src.m_size}, stack{new int[src.m_size]}, m_top{src.m_top}
    {
        memcpy(stack, src.stack, src.m_size * sizeof(int));
    }
    Stack(Stack &&other) : m_size{other.m_size}, stack{other.stack}, m_top{other.m_top}
    {
        other.m_size = 0;
        other.stack = nullptr;
    }
    void push(int value)
    {
        if (is_full())
        {
            std::cout << "Stack overflow!" << '\n';
            return;
        }
        stack[m_top++] = value;
    }
    int pop()
    {
        if (is_empty())
        {
            std::cout << "Stack underflow!" << '\n';
            return 1;
        }
        return stack[m_top--];
    }
    bool is_full() const
    {
        return m_top == m_size;
    }
    bool is_empty() const
    {
        return m_top == -1;
    }
    void preview() const
    {
        if (is_empty())
        {
            std::cout << "There is nothing to look at!" << '\n';
            return;
        }
        for (int i = 0; i < m_top; i++)
        {
            std::cout << stack[i] << '\n';
        }
    }
    void reset()
    {
        m_top = -1;
    }
    int capacity() const
    {
        return m_size;
    }

private:
    const int DEFAULT_SIZE{5};
    int m_size{};
    int m_top{-1};
    int *stack = nullptr;
};

int main()
{

    Stack test{10};

    std::cout << test.capacity() << '\n';
    int val{0};
    while (!test.is_full())
    {
        test.push(val++);
    }
    test.preview();
    Stack test2{test};
    std::cout << "The copy's capacity: " << test2.capacity() << '\n';
    test2.preview();
    return 0;
}