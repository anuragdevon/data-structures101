#[derive(Debug)]
struct Stack<T>(Vec<T>);

impl<T> Stack<T> {
    fn new() -> Stack<T> {
        Stack(Vec::<T>::new())
    }
    fn push(&mut self, item: T) {
        self.0.push(item);
    }
    fn pop(&mut self) {
        self.0.pop();
    }
    fn length(&self) -> usize {
        self.0.len()
    }
}

fn main() {
    let mut stack = Stack::<&str>::new();
    stack.push("T");
    println!("{:?}", stack);
    stack.push("A");
    println!("{:?}", stack);
    println!("Length is {}", stack.length());
    stack.pop();
    println!("{:?}", stack);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn stack_push() {
        let mut stack = Stack::<i32>::new();
        stack.push(5);
        assert_eq!(stack.0, vec![5]);
    }

    #[test]
    fn stack_pop() {
        let mut stack = Stack::<i32>::new();
        stack.push(5);
        stack.pop();
        assert_eq!(stack.0, vec![]);
    }

    #[test]
    fn stack_length() {
        let mut stack = Stack::<i32>::new();
        stack.push(5);
        stack.push(59);
        assert_eq!(stack.length(), 2);
    }
}
