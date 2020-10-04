enum Sort {
    Ascending,
    Descending
}

fn bubble_sort<T: PartialOrd>(arr: &mut [T], sort: Sort) {
    let length = arr.len();

    match sort {
        Sort::Ascending => {
            for i in 0..length-1 {
                for j in 0..length-i-1 {
                    if arr[j] > arr[j+1] {
                        arr.swap(j, j+1);
                    }
                }
            }
        },
        Sort::Descending => {
            for i in 0..length-1 {
                for j in 0..length-i-1 {
                    if arr[j] < arr[j+1] {
                        arr.swap(j, j+1);
                    }
                }
            }
        }
    }
    
}

fn main() {
    let mut vec = vec![1,4,3,6,1,3,5,2];
    println!("Before sorting: {:?}", vec);
    bubble_sort(&mut vec, Sort::Ascending);
    println!("Sorted ascending: {:?}", vec);
    bubble_sort(&mut vec, Sort::Descending);
    println!("Sorted descending: {:?}", vec);
}
