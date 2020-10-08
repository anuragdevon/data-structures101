fn binary_search<T: PartialOrd>(vec: Vec<T>, key: T) -> Option<usize> {
    let mut high: usize = vec.len() - 1;
    let mut low: usize = 0;
    let mut middle: usize;

    while low <= high {
        middle = (high + low) / 2;

        if key == vec[middle] {
            return Some(middle);
        }
        if key > vec[middle] {
            low = middle + 1;
        }
        else {
            high = middle - 1;
        }
    }

    None
}

fn main() {
    let mut vec = vec![3,5,4,1,6,4,7,9,1];
    vec.sort_unstable();
    println!("{:?}", vec);
    match binary_search(vec, 5) {
        Some(i) => println!("{:?}", i),
        None => println!("Not found!")
    }
}
