fn test_run(x: i8)->i8
{
    return x+2;
}

fn main() {
    let x = (3,4,5);

    println!("{}", test_run(x.2));
}
