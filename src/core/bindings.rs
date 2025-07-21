use crate::Core;

#[unsafe(no_mangle)]
pub extern "C" fn lines_core_create(pcore: *mut*mut Core) -> i32 {
    let core= Core { background_color: color::Rgba8 { r:0, g: 0, b: 0, a: 255,} };
    let ptr = Box::into_raw(Box::new(core));
    unsafe {
        pcore.write(ptr);
    }
    return 0;
}

#[unsafe(no_mangle)]
pub extern "C" fn lines_core_get_bg_color(core: *const Core, color: *mut color::Rgba8) {
    unsafe {
        color.write(core.read().background_color);
    }
}