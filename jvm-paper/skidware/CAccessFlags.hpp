#ifndef CACCESSFLAGS_HPP_GUARD
#define CACCESSFLAGS_HPP_GUARD
#pragma once

enum {
    JVM_ACC_PUBLIC = 0x0001,
    JVM_ACC_PRIVATE = 0x0002,
    JVM_ACC_PROTECTED = 0x0004,
    JVM_ACC_STATIC = 0x0008,
    JVM_ACC_FINAL = 0x0010,
    JVM_ACC_SYNCHRONIZED = 0x0020,
    JVM_ACC_SUPER = 0x0020,
    JVM_ACC_VOLATILE = 0x0040,
    JVM_ACC_BRIDGE = 0x0040,
    JVM_ACC_TRANSIENT = 0x0080,
    JVM_ACC_VARARGS = 0x0080,
    JVM_ACC_NATIVE = 0x0100,
    JVM_ACC_INTERFACE = 0x0200,
    JVM_ACC_ABSTRACT = 0x0400,
    JVM_ACC_STRICT = 0x0800,
    JVM_ACC_SYNTHETIC = 0x1000,
    JVM_ACC_ANNOTATION = 0x2000,
    JVM_ACC_ENUM = 0x4000,
    JVM_ACC_MODULE = 0x8000
};

#define JVM_ACC_PUBLIC_BIT        0
#define JVM_ACC_PRIVATE_BIT       1
#define JVM_ACC_PROTECTED_BIT     2
#define JVM_ACC_STATIC_BIT        3
#define JVM_ACC_FINAL_BIT         4
#define JVM_ACC_SYNCHRONIZED_BIT  5
#define JVM_ACC_SUPER_BIT         5
#define JVM_ACC_VOLATILE_BIT      6
#define JVM_ACC_BRIDGE_BIT        6
#define JVM_ACC_TRANSIENT_BIT     7
#define JVM_ACC_VARARGS_BIT       7
#define JVM_ACC_NATIVE_BIT        8
#define JVM_ACC_INTERFACE_BIT     9
#define JVM_ACC_ABSTRACT_BIT      10
#define JVM_ACC_STRICT_BIT        11
#define JVM_ACC_SYNTHETIC_BIT     12
#define JVM_ACC_ANNOTATION_BIT    13
#define JVM_ACC_ENUM_BIT          14

#define JVM_RECOGNIZED_FIELD_MODIFIERS (JVM_ACC_PUBLIC | \
                                        JVM_ACC_PRIVATE | \
                                        JVM_ACC_PROTECTED | \
                                        JVM_ACC_STATIC | \
                                        JVM_ACC_FINAL | \
                                        JVM_ACC_VOLATILE | \
                                        JVM_ACC_TRANSIENT | \
                                        JVM_ACC_ENUM | \
                                        JVM_ACC_SYNTHETIC)

enum {
    JVM_T_BOOLEAN = 4,
    JVM_T_CHAR = 5,
    JVM_T_FLOAT = 6,
    JVM_T_DOUBLE = 7,
    JVM_T_BYTE = 8,
    JVM_T_SHORT = 9,
    JVM_T_INT = 10,
    JVM_T_LONG = 11
};

enum {
    // See jvm.h for shared JVM_ACC_XXX access flags
    // HotSpot-specific access flags
    // flags actually put in .class file
    JVM_ACC_WRITTEN_FLAGS = 0x00007FFF,
    // Method* flags
    JVM_ACC_MONITOR_MATCH = 0x10000000,     // True if we know that monitorenter/monitorexit bytecodes match
    JVM_ACC_HAS_MONITOR_BYTECODES = 0x20000000,     // Method contains monitorenter/monitorexit bytecodes
    JVM_ACC_HAS_LOOPS = 0x40000000,     // Method has loops
    JVM_ACC_LOOPS_FLAG_INIT = (int)0x80000000,// The loop flag has been initialized
    JVM_ACC_QUEUED = 0x01000000,     // Queued for compilation
    JVM_ACC_NOT_C2_COMPILABLE = 0x02000000,
    JVM_ACC_NOT_C1_COMPILABLE = 0x04000000,
    JVM_ACC_NOT_C2_OSR_COMPILABLE = 0x08000000,
    JVM_ACC_HAS_LINE_NUMBER_TABLE = 0x00100000,
    JVM_ACC_HAS_CHECKED_EXCEPTIONS = 0x00400000,
    JVM_ACC_HAS_JSRS = 0x00800000,
    JVM_ACC_IS_OLD = 0x00010000,     // RedefineClasses() has replaced this method
    JVM_ACC_IS_OBSOLETE = 0x00020000,     // RedefineClasses() has made method obsolete
    JVM_ACC_IS_PREFIXED_NATIVE = 0x00040000,     // JVMTI has prefixed this native method
    JVM_ACC_ON_STACK = 0x00080000,     // RedefineClasses() was used on the stack
    JVM_ACC_IS_DELETED = 0x00008000,     // RedefineClasses() has deleted this method
    // Klass* flags
    JVM_ACC_HAS_MIRANDA_METHODS = 0x10000000,     // True if this class has miranda methods in it's vtable
    JVM_ACC_HAS_VANILLA_CONSTRUCTOR = 0x20000000,     // True if klass has a vanilla default constructor
    JVM_ACC_HAS_FINALIZER = 0x40000000,     // True if klass has a non-empty finalize() method
    JVM_ACC_IS_CLONEABLE_FAST = (int)0x80000000,// True if klass implements the Cloneable interface and can be optimized in generated code
    JVM_ACC_HAS_FINAL_METHOD = 0x01000000,     // True if klass has final method
    JVM_ACC_IS_SHARED_CLASS = 0x02000000,     // True if klass is shared
    // Klass* and Method* flags
    JVM_ACC_HAS_LOCAL_VARIABLE_TABLE = 0x00200000,
    JVM_ACC_PROMOTED_FLAGS = 0x00200000,     // flags promoted from methods to the holding klass
    // field flags
    // Note: these flags must be defined in the low order 16 bits because
    // InstanceKlass only stores a ushort worth of information from the
    // AccessFlags value.
    // These bits must not conflict with any other field-related access flags
    // (e.g., ACC_ENUM).
    // Note that the class-related ACC_ANNOTATION bit conflicts with these flags.
    JVM_ACC_FIELD_ACCESS_WATCHED = 0x00002000, // field access is watched by JVMTI
    JVM_ACC_FIELD_MODIFICATION_WATCHED = 0x00008000, // field modification is watched by JVMTI
    JVM_ACC_FIELD_INTERNAL = 0x00000400, // internal field, same as JVM_ACC_ABSTRACT
    JVM_ACC_FIELD_STABLE = 0x00000020, // @Stable field, same as JVM_ACC_SYNCHRONIZED and JVM_ACC_SUPER
    JVM_ACC_FIELD_INITIALIZED_FINAL_UPDATE = 0x00000100, // (static) final field updated outside (class) initializer, same as JVM_ACC_NATIVE
    JVM_ACC_FIELD_HAS_GENERIC_SIGNATURE = 0x00000800, // field has generic signature
    JVM_ACC_FIELD_INTERNAL_FLAGS = JVM_ACC_FIELD_ACCESS_WATCHED |
    JVM_ACC_FIELD_MODIFICATION_WATCHED |
    JVM_ACC_FIELD_INTERNAL |
    JVM_ACC_FIELD_STABLE |
    JVM_ACC_FIELD_HAS_GENERIC_SIGNATURE,
    // flags accepted by set_field_flags()
    JVM_ACC_FIELD_FLAGS = JVM_RECOGNIZED_FIELD_MODIFIERS | JVM_ACC_FIELD_INTERNAL_FLAGS
};

class CAccessFlags {
public:
    long _flags;
    bool is_public() const { return (_flags & JVM_ACC_PUBLIC) != 0; }
    bool is_private() const { return (_flags & JVM_ACC_PRIVATE) != 0; }
    bool is_protected() const { return (_flags & JVM_ACC_PROTECTED) != 0; }
    bool is_static() const { return (_flags & JVM_ACC_STATIC) != 0; }
    bool is_final() const { return (_flags & JVM_ACC_FINAL) != 0; }
    bool is_synchronized() const { return (_flags & JVM_ACC_SYNCHRONIZED) != 0; }
    bool is_super() const { return (_flags & JVM_ACC_SUPER) != 0; }
    bool is_volatile() const { return (_flags & JVM_ACC_VOLATILE) != 0; }
    bool is_transient() const { return (_flags & JVM_ACC_TRANSIENT) != 0; }
    bool is_native() const { return (_flags & JVM_ACC_NATIVE) != 0; }
    bool is_interface() const { return (_flags & JVM_ACC_INTERFACE) != 0; }
    bool is_abstract() const { return (_flags & JVM_ACC_ABSTRACT) != 0; }
    bool is_strict() const { return (_flags & JVM_ACC_STRICT) != 0; }
    // Attribute flags
    bool is_synthetic() const { return (_flags & JVM_ACC_SYNTHETIC) != 0; }
    // Method* flags
    bool is_monitor_matching() const { return (_flags & JVM_ACC_MONITOR_MATCH) != 0; }
    bool has_monitor_bytecodes() const { return (_flags & JVM_ACC_HAS_MONITOR_BYTECODES) != 0; }
    bool has_loops() const { return (_flags & JVM_ACC_HAS_LOOPS) != 0; }
    bool loops_flag_init() const { return (_flags & JVM_ACC_LOOPS_FLAG_INIT) != 0; }
    bool queued_for_compilation() const { return (_flags & JVM_ACC_QUEUED) != 0; }
    bool is_not_c1_compilable() const { return (_flags & JVM_ACC_NOT_C1_COMPILABLE) != 0; }
    bool is_not_c2_compilable() const { return (_flags & JVM_ACC_NOT_C2_COMPILABLE) != 0; }
    bool is_not_c2_osr_compilable() const { return (_flags & JVM_ACC_NOT_C2_OSR_COMPILABLE) != 0; }
    bool has_linenumber_table() const { return (_flags & JVM_ACC_HAS_LINE_NUMBER_TABLE) != 0; }
    bool has_checked_exceptions() const { return (_flags & JVM_ACC_HAS_CHECKED_EXCEPTIONS) != 0; }
    bool has_jsrs() const { return (_flags & JVM_ACC_HAS_JSRS) != 0; }
    bool is_old() const { return (_flags & JVM_ACC_IS_OLD) != 0; }
    bool is_obsolete() const { return (_flags & JVM_ACC_IS_OBSOLETE) != 0; }
    bool is_deleted() const { return (_flags & JVM_ACC_IS_DELETED) != 0; }
    bool is_prefixed_native() const { return (_flags & JVM_ACC_IS_PREFIXED_NATIVE) != 0; }
    // Klass* flags
    bool has_miranda_methods() const { return (_flags & JVM_ACC_HAS_MIRANDA_METHODS) != 0; }
    bool has_vanilla_constructor() const { return (_flags & JVM_ACC_HAS_VANILLA_CONSTRUCTOR) != 0; }
    bool has_finalizer() const { return (_flags & JVM_ACC_HAS_FINALIZER) != 0; }
    bool has_final_method() const { return (_flags & JVM_ACC_HAS_FINAL_METHOD) != 0; }
    bool is_cloneable_fast() const { return (_flags & JVM_ACC_IS_CLONEABLE_FAST) != 0; }
    bool is_shared_class() const { return (_flags & JVM_ACC_IS_SHARED_CLASS) != 0; }
    // Klass* and Method* flags
    bool has_localvariable_table() const { return (_flags & JVM_ACC_HAS_LOCAL_VARIABLE_TABLE) != 0; }
    // field flags
    bool is_field_access_watched() const { return (_flags & JVM_ACC_FIELD_ACCESS_WATCHED) != 0; }
    bool is_field_modification_watched() const
    {
        return (_flags & JVM_ACC_FIELD_MODIFICATION_WATCHED) != 0;
    }
    bool has_field_initialized_final_update() const
    {
        return (_flags & JVM_ACC_FIELD_INITIALIZED_FINAL_UPDATE) != 0;
    }
    bool on_stack() const { return (_flags & JVM_ACC_ON_STACK) != 0; }
    bool is_internal() const { return (_flags & JVM_ACC_FIELD_INTERNAL) != 0; }
    bool is_stable() const { return (_flags & JVM_ACC_FIELD_STABLE) != 0; }
    bool field_has_generic_signature() const
    {
        return (_flags & JVM_ACC_FIELD_HAS_GENERIC_SIGNATURE) != 0;
    }
    // get .class file flags
    long get_flags() const { return (_flags & JVM_ACC_WRITTEN_FLAGS); }
};

#endif //CACCESSFLAGS_HPP_GUARD