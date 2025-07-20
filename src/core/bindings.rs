use crate::Core;

#[no_mangle]
pub extern "C" fn lines_core_increment_counter() -> i32 {
    unsafe {
        Core.counter+=1;
        return Core.counter;
    }
}