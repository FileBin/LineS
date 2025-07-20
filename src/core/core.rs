pub mod bindings;

struct Core {
    counter: i32,
}

pub static mut Core: Core = Core { counter: 0 };