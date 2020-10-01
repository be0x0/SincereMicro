#include <backends/cxxrtl/cxxrtl.h>

#if defined(CXXRTL_INCLUDE_CAPI_IMPL) || \
    defined(CXXRTL_INCLUDE_VCD_CAPI_IMPL)
#include <backends/cxxrtl/cxxrtl_capi.cc>
#endif

#if defined(CXXRTL_INCLUDE_VCD_CAPI_IMPL)
#include <backends/cxxrtl/cxxrtl_vcd_capi.cc>
#endif

using namespace cxxrtl_yosys;

namespace cxxrtl_design {

// \cells_not_processed: 1
// \src: alu/sub.v:1.1-14.10
struct p_sub : public module {
	// \src: alu/sub.v:3.21-3.24
	/*output*/ wire<11> p_out;
	// \src: alu/sub.v:2.29-2.32
	/*input*/ value<11> p_acc;
	// \src: alu/sub.v:2.23-2.27
	/*input*/ value<11> p_arg1;

	bool eval() override;
	bool commit() override;
	void debug_info(debug_items &items, std::string path = "") override;
}; // struct p_sub

bool p_sub::eval() {
	bool converged = false;
	value<11> i_procmux_24_196__Y;
	// \src: alu/sub.v:10.8-10.15
	value<1> i_gt_24_alu_2f_sub_2e_v_3a_10_24_187__Y;
	// \src: alu/sub.v:9.3-13.6
	value<11> i_0_5c_out_5b_10_3a_0_5d_;
	// \src: alu/sub.v:5.22-5.25
	value<12> p_tmp;
	// connection
	p_tmp = sub_ss<12>(p_acc, p_arg1);
	// \src: alu/sub.v:10.8-10.15
	// cell $gt$alu/sub.v:10$187
	i_gt_24_alu_2f_sub_2e_v_3a_10_24_187__Y = gt_ss<1>(p_tmp, value<32>{0x3e7u});
	// cells $procmux$193 $procmux$190 $lt$alu/sub.v:11$188
	i_procmux_24_196__Y = (i_gt_24_alu_2f_sub_2e_v_3a_10_24_187__Y ? value<11>{0x3e7u} : (i_gt_24_alu_2f_sub_2e_v_3a_10_24_187__Y ? value<11>{0u} : (lt_ss<1>(p_tmp, value<32>{0xfffffc19u}) ? value<11>{0x419u} : p_tmp.slice<10,0>().val())));
	// connection
	p_out.next = i_procmux_24_196__Y;
	// connection
	i_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_196__Y;
	return converged;
}

bool p_sub::commit() {
	bool changed = false;
	changed |= p_out.commit();
	return changed;
}

void p_sub::debug_info(debug_items &items, std::string path) {
	assert(path.empty() || path[path.size() - 1] == ' ');
	items.add(path + "out", debug_item(p_out, 0));
	items.add(path + "acc", debug_item(p_acc, 0));
	items.add(path + "arg1", debug_item(p_arg1, 0));
}

// \cells_not_processed: 1
// \src: MCX.v:1.1-105.10
struct p_MCX : public module {
	wire<4> i_procmux_24_933__Y;
	wire<7> i_procmux_24_918__Y;
	wire<1> i_procmux_24_914__Y;
	// \src: MCX.v:17.22-17.25
	wire<7> p_p0r;
	// \src: MCX.v:14.15-14.24
	wire<4> p_next__inst;
	// \src: MCX.v:13.23-13.26
	wire<11> p_acc;
	// \src: MCX.v:3.21-3.23
	/*inout*/ wire<7> p_p1;
	// \src: MCX.v:3.17-3.19
	/*inout*/ wire<7> p_p0;
	// \src: MCX.v:2.16-2.20
	/*input*/ value<1> p_nrst;
	// \src: MCX.v:2.11-2.14
	/*input*/ value<1> p_clk;
	value<1> prev_p_clk;
	bool posedge_p_clk() const {
		return !prev_p_clk.slice<0>().val() && p_clk.slice<0>().val();
	}

	bool eval() override;
	bool commit() override;
	void debug_info(debug_items &items, std::string path = "") override;
}; // struct p_MCX

bool p_MCX::eval() {
	bool converged = false;
	bool posedge_p_clk = this->posedge_p_clk();
	value<1> i_auto_24_rtlil_2e_cc_3a_2125_3a_ReduceOr_24_965;
	value<11> i_procmux_24_924__Y;
	value<11> i_procmux_24_910__Y;
	value<11> i_procmux_24_907__Y;
	value<11> i_procmux_24_898__Y;
	value<11> i_procmux_24_889__Y;
	value<11> i_procmux_24_877__Y;
	value<42> i_procmux_24_874__Y;
	value<42> i_procmux_24_871__Y;
	value<42> i_procmux_24_868__Y;
	value<42> i_procmux_24_865__Y;
	value<42> i_procmux_24_856__Y;
	// \hdlname: MEM addr
	// \src: MCX.v:30.14-30.60|prog_mem.v:3.17-3.21
	value<4> p_MEM_2e_addr;
	// \hdlname: MEM mem[0]
	// \src: MCX.v:30.14-30.60|prog_mem.v:6.16-6.19
	value<42> p_MEM_2e_mem_5b_0_5d_;
	// \hdlname: MEM mem[1]
	// \src: MCX.v:30.14-30.60|prog_mem.v:6.16-6.19
	value<42> p_MEM_2e_mem_5b_1_5d_;
	// \hdlname: MEM mem[2]
	// \src: MCX.v:30.14-30.60|prog_mem.v:6.16-6.19
	value<42> p_MEM_2e_mem_5b_2_5d_;
	// \hdlname: MEM mem[3]
	// \src: MCX.v:30.14-30.60|prog_mem.v:6.16-6.19
	value<42> p_MEM_2e_mem_5b_3_5d_;
	// \hdlname: MEM mem[4]
	// \src: MCX.v:30.14-30.60|prog_mem.v:6.16-6.19
	value<42> p_MEM_2e_mem_5b_4_5d_;
	// \hdlname: MEM mem[5]
	// \src: MCX.v:30.14-30.60|prog_mem.v:6.16-6.19
	value<42> p_MEM_2e_mem_5b_5_5d_;
	// \hdlname: MEM mem[6]
	// \src: MCX.v:30.14-30.60|prog_mem.v:6.16-6.19
	value<42> p_MEM_2e_mem_5b_6_5d_;
	// \nosync: 1
	// \src: MCX.v:30.14-30.60|prog_mem.v:0.0-0.0
	value<3> i_flatten_5c_MEM_2e__24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__ADDR;
	// \nosync: 1
	// \src: MCX.v:30.14-30.60|prog_mem.v:0.0-0.0
	value<42> i_flatten_5c_MEM_2e__24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA;
	// \src: MCX.v:30.14-30.60|prog_mem.v:8.5-10.8
	value<46> i_flatten_5c_MEM_2e__24_0_5c_line_5b_45_3a_0_5d_;
	// \src: MCX.v:30.14-30.60|prog_mem.v:8.5-10.8
	value<3> i_flatten_5c_MEM_2e__24_0_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__ADDR_5b_2_3a_0_5d__24_29;
	// \src: MCX.v:30.14-30.60|prog_mem.v:8.5-10.8
	value<42> i_flatten_5c_MEM_2e__24_0_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA_5b_41_3a_0_5d__24_30;
	// \src: MCX.v:30.14-30.60|prog_mem.v:8.5-10.8
	value<42> i_flatten_5c_MEM_2e__24_1_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA_5b_41_3a_0_5d__24_31;
	// \src: MCX.v:30.14-30.60|prog_mem.v:13.5-29.8
	value<42> i_flatten_5c_MEM_2e__24_0_5c_mem_5b_0_5d__5b_41_3a_0_5d_;
	// \src: MCX.v:30.14-30.60|prog_mem.v:13.5-29.8
	value<42> i_flatten_5c_MEM_2e__24_0_5c_mem_5b_1_5d__5b_41_3a_0_5d_;
	// \src: MCX.v:30.14-30.60|prog_mem.v:13.5-29.8
	value<42> i_flatten_5c_MEM_2e__24_0_5c_mem_5b_2_5d__5b_41_3a_0_5d_;
	// \src: MCX.v:30.14-30.60|prog_mem.v:13.5-29.8
	value<42> i_flatten_5c_MEM_2e__24_0_5c_mem_5b_3_5d__5b_41_3a_0_5d_;
	// \src: MCX.v:30.14-30.60|prog_mem.v:14.12-14.16
	value<1> i_flatten_5c_MEM_2e__24_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y;
	// \hdlname: ALU1 inst
	// \src: MCX.v:29.9-29.90|alu/alu.v:8.20-8.24
	value<4> p_ALU1_2e_inst;
	// \hdlname: ALU1 arg1
	// \src: MCX.v:29.9-29.90|alu/alu.v:9.21-9.25
	value<11> p_ALU1_2e_arg1;
	// \hdlname: ALU1 arg2
	// \src: MCX.v:29.9-29.90|alu/alu.v:9.27-9.31
	value<11> p_ALU1_2e_arg2;
	// \hdlname: ALU1 acc
	// \src: MCX.v:29.9-29.90|alu/alu.v:9.33-9.36
	value<11> p_ALU1_2e_acc;
	// \src: MCX.v:29.9-29.90|alu/alu.v:23.3-33.6
	value<11> i_flatten_5c_ALU1_2e__24_0_5c_out_5b_10_3a_0_5d_;
	// \src: MCX.v:29.9-29.90|alu/add.v:12.8-12.15|alu/alu.v:16.7-16.50
	value<1> i_flatten_5c_ALU1_2e__5c_UADD_2e__24_gt_24_alu_2f_add_2e_v_3a_12_24_36__Y;
	// \src: MCX.v:29.9-29.90|alu/add.v:11.3-15.6|alu/alu.v:16.7-16.50
	value<11> i_flatten_5c_ALU1_2e__5c_UADD_2e__24_0_5c_out_5b_10_3a_0_5d_;
	// \hdlname: ALU1 UADD tmp
	// \src: MCX.v:29.9-29.90|alu/add.v:7.22-7.25|alu/alu.v:16.7-16.50
	value<12> p_ALU1_2e_UADD_2e_tmp;
	// \src: MCX.v:29.9-29.90|alu/sub.v:10.8-10.15|alu/alu.v:17.7-17.50
	value<1> i_flatten_5c_ALU1_2e__5c_USUB_2e__24_gt_24_alu_2f_sub_2e_v_3a_10_24_187__Y;
	// \src: MCX.v:29.9-29.90|alu/sub.v:9.3-13.6|alu/alu.v:17.7-17.50
	value<11> i_flatten_5c_ALU1_2e__5c_USUB_2e__24_0_5c_out_5b_10_3a_0_5d_;
	// \hdlname: ALU1 USUB tmp
	// \src: MCX.v:29.9-29.90|alu/sub.v:5.22-5.25|alu/alu.v:17.7-17.50
	value<12> p_ALU1_2e_USUB_2e_tmp;
	// \src: MCX.v:29.9-29.90|alu/mul.v:11.8-11.17|alu/alu.v:18.7-18.50
	value<1> i_flatten_5c_ALU1_2e__5c_UMUL_2e__24_gt_24_alu_2f_mul_2e_v_3a_11_24_181__Y;
	// \src: MCX.v:29.9-29.90|alu/mul.v:10.3-14.6|alu/alu.v:18.7-18.50
	value<11> i_flatten_5c_ALU1_2e__5c_UMUL_2e__24_0_5c_out_5b_10_3a_0_5d_;
	// \hdlname: ALU1 UMUL tmp
	// \src: MCX.v:29.9-29.90|alu/mul.v:7.22-7.25|alu/alu.v:18.7-18.50
	value<22> p_ALU1_2e_UMUL_2e_tmp;
	// \src: MCX.v:29.9-29.90|alu/notop.v:5.3-11.6|alu/alu.v:19.9-19.39
	value<11> i_flatten_5c_ALU1_2e__5c_UNOT_2e__24_0_5c_out_5b_10_3a_0_5d_;
	// \src: MCX.v:94.20-94.38
	value<1> i_eq_24_MCX_2e_v_3a_94_24_26__Y;
	// \src: MCX.v:94.31-94.38
	value<1> p_p1__addr;
	// \src: MCX.v:92.16-92.28
	value<1> i_eq_24_MCX_2e_v_3a_92_24_25__Y;
	// \src: MCX.v:86.12-86.17
	value<1> i_logic__not_24_MCX_2e_v_3a_86_24_24__Y;
	// \src: MCX.v:85.5-100.8
	value<1> i_0_5c_p0oe_5b_0_3a_0_5d_;
	// \src: MCX.v:85.5-100.8
	value<7> i_0_5c_p0w_5b_6_3a_0_5d_;
	// \src: MCX.v:85.5-100.8
	value<7> i_0_5c_p0r_5b_6_3a_0_5d_;
	// \src: MCX.v:74.12-74.17
	value<1> i_logic__not_24_MCX_2e_v_3a_74_24_20__Y;
	// \src: MCX.v:73.5-82.8
	value<11> i_0_5c_acc_5b_10_3a_0_5d_;
	// \src: MCX.v:64.16-64.28
	value<1> i_eq_24_MCX_2e_v_3a_64_24_15__Y;
	// \src: MCX.v:63.5-70.8
	value<12> i_0_24_mem2bits_24__5c_args_24_MCX_2e_v_3a_65_24_5_5b_11_3a_0_5d__24_14;
	// \src: MCX.v:63.5-70.8
	value<4> i_0_5c_next__inst_5b_3_3a_0_5d_;
	// \src: MCX.v:44.12-44.17
	value<1> i_logic__not_24_MCX_2e_v_3a_44_24_12__Y;
	// \src: MCX.v:43.5-60.8
	value<12> i_0_5c_args_5b_2_5d__5b_11_3a_0_5d_;
	// \src: MCX.v:43.5-60.8
	value<12> i_0_5c_args_5b_1_5d__5b_11_3a_0_5d_;
	// \src: MCX.v:43.5-60.8
	value<12> i_0_5c_args_5b_0_5d__5b_11_3a_0_5d_;
	// \src: MCX.v:43.5-60.8
	value<4> i_0_5c_inst_5b_3_3a_0_5d_;
	// \src: MCX.v:43.5-60.8
	value<2> i_0_5c_cond_5b_1_3a_0_5d_;
	// \src: MCX.v:43.5-60.8
	value<4> i_0_5c_PC_5b_3_3a_0_5d_;
	// \src: MCX.v:36.5-40.8
	value<11> i_0_5c_numArgs_5b_1_5d__5b_10_3a_0_5d_;
	// \src: MCX.v:36.5-40.8
	value<11> i_0_5c_numArgs_5b_0_5d__5b_10_3a_0_5d_;
	// \src: MCX.v:36.5-40.8
	value<12> i_0_24_mem2bits_24__5c_args_24_MCX_2e_v_3a_38_24_4_5b_11_3a_0_5d__24_10;
	// \src: MCX.v:36.5-40.8
	value<12> i_0_24_mem2bits_24__5c_args_24_MCX_2e_v_3a_38_24_3_5b_11_3a_0_5d__24_9;
	// \src: MCX.v:36.5-40.8
	value<1> i_0_5c_i_5b_0_3a_0_5d_;
	// \src: MCX.v:24.17-24.21
	value<1> p_p1oe;
	// \src: MCX.v:23.17-23.21
	value<1> p_p0oe;
	// \src: MCX.v:9.23-9.27
	value<12> p_args_5b_2_5d_;
	// \src: MCX.v:9.23-9.27
	value<12> p_args_5b_1_5d_;
	// \src: MCX.v:9.23-9.27
	value<12> p_args_5b_0_5d_;
	// \src: MCX.v:10.23-10.30
	value<11> p_numArgs_5b_2_5d_;
	// \src: MCX.v:10.23-10.30
	value<11> p_numArgs_5b_1_5d_;
	// \src: MCX.v:10.23-10.30
	value<11> p_numArgs_5b_0_5d_;
	// \nosync: 1
	// \src: MCX.v:0.0-0.0
	value<12> i_mem2bits_24__5c_args_24_MCX_2e_v_3a_38_24_4;
	// \nosync: 1
	// \src: MCX.v:0.0-0.0
	value<12> i_mem2bits_24__5c_args_24_MCX_2e_v_3a_38_24_3;
	// \src: MCX.v:35.9-35.10
	value<1> p_i;
	// \src: MCX.v:20.22-20.25
	value<7> p_p1w;
	// \src: MCX.v:19.22-19.25
	value<7> p_p1r;
	// \src: MCX.v:18.22-18.25
	value<7> p_p0w;
	// \src: MCX.v:15.17-15.21
	value<46> p_line;
	// \src: MCX.v:8.15-8.19
	value<4> p_inst;
	// \src: MCX.v:7.15-7.19
	value<2> p_cond;
	// \src: MCX.v:6.15-6.17
	value<4> p_PC;
	// \src: MCX.v:30.14-30.60|prog_mem.v:14.12-14.16
	// cell $flatten\MEM.$logic_not$prog_mem.v:14$33
	i_flatten_5c_MEM_2e__24_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y = logic_not<1>(p_nrst);
	// \full_case: 1
	// \src: prog_mem.v:14.9-28.12
	// cell $procmux$865
	i_procmux_24_865__Y = (i_flatten_5c_MEM_2e__24_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y ? value<42>{0x1000000u,0x20u} : value<42>{0x1000000u,0x20u});
	// \full_case: 1
	// \src: prog_mem.v:14.9-28.12
	// cell $procmux$868
	i_procmux_24_868__Y = (i_flatten_5c_MEM_2e__24_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y ? value<42>{0u,0x80u} : value<42>{0u,0x80u});
	// \full_case: 1
	// \src: prog_mem.v:14.9-28.12
	// cell $procmux$871
	i_procmux_24_871__Y = (i_flatten_5c_MEM_2e__24_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y ? value<42>{0u,0u} : value<42>{0u,0u});
	// \full_case: 1
	// \src: prog_mem.v:14.9-28.12
	// cell $procmux$874
	i_procmux_24_874__Y = (i_flatten_5c_MEM_2e__24_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y ? value<42>{0x96801000u,0x10u} : value<42>{0x96801000u,0x10u});
	// cells $auto$proc_dlatch.cc:257:make_hold$962 $auto$proc_dlatch.cc:253:make_hold$960 $auto$proc_dlatch.cc:244:make_hold$958
	i_auto_24_rtlil_2e_cc_3a_2125_3a_ReduceOr_24_965 = reduce_or<1>(and_uu<1>(not_u<1>(i_flatten_5c_MEM_2e__24_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y), reduce_or<1>(value<1>{0x1u})));
	// \src: MCX.v:30.14-30.60|prog_mem.v:13.5-29.8
	// cell $auto$proc_dlatch.cc:430:proc_dlatch$977
	if (not_u<1>(i_auto_24_rtlil_2e_cc_3a_2125_3a_ReduceOr_24_965) == value<1> {1u}) {
		p_MEM_2e_mem_5b_0_5d_ = i_procmux_24_874__Y;
	}
	// \src: MCX.v:30.14-30.60|prog_mem.v:13.5-29.8
	// cell $auto$proc_dlatch.cc:430:proc_dlatch$974
	if (not_u<1>(i_auto_24_rtlil_2e_cc_3a_2125_3a_ReduceOr_24_965) == value<1> {1u}) {
		p_MEM_2e_mem_5b_1_5d_ = i_procmux_24_871__Y;
	}
	// \src: MCX.v:30.14-30.60|prog_mem.v:13.5-29.8
	// cell $auto$proc_dlatch.cc:430:proc_dlatch$971
	if (not_u<1>(i_auto_24_rtlil_2e_cc_3a_2125_3a_ReduceOr_24_965) == value<1> {1u}) {
		p_MEM_2e_mem_5b_2_5d_ = i_procmux_24_868__Y;
	}
	// \src: MCX.v:30.14-30.60|prog_mem.v:13.5-29.8
	// cell $auto$proc_dlatch.cc:430:proc_dlatch$968
	if (not_u<1>(i_auto_24_rtlil_2e_cc_3a_2125_3a_ReduceOr_24_965) == value<1> {1u}) {
		p_MEM_2e_mem_5b_3_5d_ = i_procmux_24_865__Y;
	}
	// connection
	p_MEM_2e_addr = p_next__inst.curr;
	// cells $procmux$857_CMP0 $procmux$858_CMP0 $procmux$859_CMP0 $procmux$860_CMP0 $procmux$861_CMP0 $procmux$862_CMP0 $procmux$863_CMP0
	i_procmux_24_856__Y = (eq_uu<1>(p_MEM_2e_addr.slice<2,0>().val(), value<3>{0x6u}) ? p_MEM_2e_mem_5b_6_5d_ : (eq_uu<1>(p_MEM_2e_addr.slice<2,0>().val(), value<3>{0x5u}) ? p_MEM_2e_mem_5b_5_5d_ : (eq_uu<1>(p_MEM_2e_addr.slice<2,0>().val(), value<3>{0x4u}) ? p_MEM_2e_mem_5b_4_5d_ : (eq_uu<1>(p_MEM_2e_addr.slice<2,0>().val(), value<3>{0x3u}) ? p_MEM_2e_mem_5b_3_5d_ : (eq_uu<1>(p_MEM_2e_addr.slice<2,0>().val(), value<3>{0x2u}) ? p_MEM_2e_mem_5b_2_5d_ : (eq_uu<1>(p_MEM_2e_addr.slice<2,0>().val(), value<3>{0x1u}) ? p_MEM_2e_mem_5b_1_5d_ : (eq_uu<1>(p_MEM_2e_addr.slice<2,0>().val(), value<3>{0u}) ? p_MEM_2e_mem_5b_0_5d_ : value<42>{0u,0u})))))));
	// \src: MCX.v:43.5-60.8
	// cell $procdff$985
	if (posedge_p_clk) {
		p_args_5b_0_5d_ = i_procmux_24_856__Y.slice<35,24>().val();
	}
	if (p_nrst == value<1> {0u}) {
		p_args_5b_0_5d_ = value<12>{0u};
	}
	// \src: MCX.v:43.5-60.8
	// cell $procdff$984
	if (posedge_p_clk) {
		p_inst = i_procmux_24_856__Y.slice<39,36>().val();
	}
	if (p_nrst == value<1> {0u}) {
		p_inst = value<4>{0u};
	}
	// \src: MCX.v:43.5-60.8
	// cell $procdff$986
	if (posedge_p_clk) {
		p_args_5b_1_5d_ = i_procmux_24_856__Y.slice<23,12>().val();
	}
	if (p_nrst == value<1> {0u}) {
		p_args_5b_1_5d_ = value<12>{0u};
	}
	// connection
	p_numArgs_5b_0_5d_ = p_args_5b_0_5d_.slice<10,0>().val();
	// \src: MCX.v:94.20-94.38
	// cell $eq$MCX.v:94$26
	i_eq_24_MCX_2e_v_3a_94_24_26__Y = eq_uu<1>(p_args_5b_0_5d_, p_p1__addr);
	// connection
	p_ALU1_2e_inst = p_inst;
	// \src: MCX.v:92.16-92.28
	// cell $eq$MCX.v:92$25
	i_eq_24_MCX_2e_v_3a_92_24_25__Y = eq_uu<1>(p_inst, value<4>{0x1u});
	// \src: MCX.v:64.16-64.28
	// cell $eq$MCX.v:64$15
	i_eq_24_MCX_2e_v_3a_64_24_15__Y = eq_uu<1>(p_inst, value<4>{0x2u});
	// connection
	p_numArgs_5b_1_5d_ = p_args_5b_1_5d_.slice<10,0>().val();
	// connection
	p_ALU1_2e_arg1 = p_numArgs_5b_0_5d_;
	// connection
	p_ALU1_2e_acc = p_acc.curr;
	// connection
	p_ALU1_2e_UADD_2e_tmp = add_ss<12>(p_ALU1_2e_acc, p_ALU1_2e_arg1);
	// connection
	p_ALU1_2e_USUB_2e_tmp = sub_ss<12>(p_ALU1_2e_acc, p_ALU1_2e_arg1);
	// connection
	p_ALU1_2e_UMUL_2e_tmp = mul_ss<22>(p_ALU1_2e_acc, p_ALU1_2e_arg1);
	// \src: MCX.v:29.9-29.90|alu/add.v:12.8-12.15|alu/alu.v:16.7-16.50
	// cell $flatten\ALU1.\UADD.$gt$alu/add.v:12$36
	i_flatten_5c_ALU1_2e__5c_UADD_2e__24_gt_24_alu_2f_add_2e_v_3a_12_24_36__Y = gt_ss<1>(p_ALU1_2e_UADD_2e_tmp, value<32>{0x3e7u});
	// \src: MCX.v:29.9-29.90|alu/sub.v:10.8-10.15|alu/alu.v:17.7-17.50
	// cell $flatten\ALU1.\USUB.$gt$alu/sub.v:10$187
	i_flatten_5c_ALU1_2e__5c_USUB_2e__24_gt_24_alu_2f_sub_2e_v_3a_10_24_187__Y = gt_ss<1>(p_ALU1_2e_USUB_2e_tmp, value<32>{0x3e7u});
	// \src: MCX.v:29.9-29.90|alu/mul.v:11.8-11.17|alu/alu.v:18.7-18.50
	// cell $flatten\ALU1.\UMUL.$gt$alu/mul.v:11$181
	i_flatten_5c_ALU1_2e__5c_UMUL_2e__24_gt_24_alu_2f_mul_2e_v_3a_11_24_181__Y = gt_ss<1>(p_ALU1_2e_UMUL_2e_tmp, value<32>{0x3e7u});
	// cells $flatten\ALU1.\UNOT.$eq$alu/notop.v:7$184
	i_procmux_24_910__Y = (eq_ss<1>(p_ALU1_2e_acc, value<32>{0u}) ? value<11>{0x64u} : value<11>{0u});
	// cells $procmux$886 $procmux$883 $flatten\ALU1.\UADD.$lt$alu/add.v:13$37
	i_procmux_24_889__Y = (i_flatten_5c_ALU1_2e__5c_UADD_2e__24_gt_24_alu_2f_add_2e_v_3a_12_24_36__Y ? value<11>{0x3e7u} : (i_flatten_5c_ALU1_2e__5c_UADD_2e__24_gt_24_alu_2f_add_2e_v_3a_12_24_36__Y ? value<11>{0u} : (lt_ss<1>(p_ALU1_2e_UADD_2e_tmp, value<32>{0xfffffc19u}) ? value<11>{0x419u} : p_ALU1_2e_UADD_2e_tmp.slice<10,0>().val())));
	// cells $procmux$895 $procmux$892 $flatten\ALU1.\USUB.$lt$alu/sub.v:11$188
	i_procmux_24_898__Y = (i_flatten_5c_ALU1_2e__5c_USUB_2e__24_gt_24_alu_2f_sub_2e_v_3a_10_24_187__Y ? value<11>{0x3e7u} : (i_flatten_5c_ALU1_2e__5c_USUB_2e__24_gt_24_alu_2f_sub_2e_v_3a_10_24_187__Y ? value<11>{0u} : (lt_ss<1>(p_ALU1_2e_USUB_2e_tmp, value<32>{0xfffffc19u}) ? value<11>{0x419u} : p_ALU1_2e_USUB_2e_tmp.slice<10,0>().val())));
	// cells $procmux$904 $procmux$901 $flatten\ALU1.\UMUL.$lt$alu/mul.v:12$182
	i_procmux_24_907__Y = (i_flatten_5c_ALU1_2e__5c_UMUL_2e__24_gt_24_alu_2f_mul_2e_v_3a_11_24_181__Y ? value<11>{0x3e7u} : (i_flatten_5c_ALU1_2e__5c_UMUL_2e__24_gt_24_alu_2f_mul_2e_v_3a_11_24_181__Y ? value<11>{0u} : (lt_ss<1>(p_ALU1_2e_UMUL_2e_tmp, value<32>{0xfffffc19u}) ? value<11>{0x419u} : p_ALU1_2e_UMUL_2e_tmp.slice<10,0>().val())));
	// cells $procmux$878_CMP0 $procmux$879_CMP0 $procmux$880_CMP0 $procmux$881_CMP0
	i_procmux_24_877__Y = (eq_uu<1>(p_ALU1_2e_inst, value<4>{0x8u}) ? i_procmux_24_910__Y : (eq_uu<1>(p_ALU1_2e_inst, value<4>{0x7u}) ? i_procmux_24_907__Y : (eq_uu<1>(p_ALU1_2e_inst, value<4>{0x6u}) ? i_procmux_24_898__Y : (eq_uu<1>(p_ALU1_2e_inst, value<4>{0x5u}) ? i_procmux_24_889__Y : p_ALU1_2e_acc))));
	// \src: MCX.v:43.5-60.8
	// cell $procdff$982
	if (posedge_p_clk) {
		p_PC = i_procmux_24_933__Y.curr;
	}
	if (p_nrst == value<1> {0u}) {
		p_PC = value<4>{0xfu};
	}
	// \src: MCX.v:85.5-100.8
	// cell $procdff$979
	if (posedge_p_clk) {
		p_p0w = i_procmux_24_918__Y.curr;
	}
	if (p_nrst == value<1> {0u}) {
		p_p0w = value<7>{0u};
	}
	// \src: MCX.v:85.5-100.8
	// cell $procdff$980
	if (posedge_p_clk) {
		p_p0oe = i_procmux_24_914__Y.curr;
	}
	if (p_nrst == value<1> {0u}) {
		p_p0oe = value<1>{0u};
	}
	// \src: MCX.v:85.5-100.8
	// cell $procdff$978
	if (posedge_p_clk) {
		p_p0r.next = p_p0r.curr;
	}
	if (p_nrst == value<1> {0u}) {
		p_p0r.next = value<7>{0u};
	}
	// cells $ne$MCX.v:78$21 $procmux$921 $eq$MCX.v:79$22
	i_procmux_24_924__Y = (ne_uu<1>(p_inst, value<4>{0x1u}) ? i_procmux_24_877__Y : (eq_uu<1>(p_args_5b_1_5d_, value<12>{0x801u}) ? p_numArgs_5b_0_5d_ : p_acc.curr));
	// \src: MCX.v:73.5-82.8
	// cell $procdff$981
	if (posedge_p_clk) {
		p_acc.next = i_procmux_24_924__Y;
	}
	if (p_nrst == value<1> {0u}) {
		p_acc.next = value<11>{0u};
	}
	// cells $procmux$912
	i_procmux_24_914__Y.next = (i_eq_24_MCX_2e_v_3a_92_24_25__Y ? (i_eq_24_MCX_2e_v_3a_94_24_26__Y ? value<1>{0u} : p_p0oe) : p_p0oe);
	// cells $procmux$916
	i_procmux_24_918__Y.next = (i_eq_24_MCX_2e_v_3a_92_24_25__Y ? (i_eq_24_MCX_2e_v_3a_94_24_26__Y ? p_numArgs_5b_1_5d_.slice<6,0>().val() : p_p0w) : p_p0w);
	// cells $procmux$930 $procmux$927 $eq$MCX.v:66$17 $add$MCX.v:69$18
	i_procmux_24_933__Y.next = (i_eq_24_MCX_2e_v_3a_64_24_15__Y ? p_args_5b_0_5d_.slice<3,0>().val() : (i_eq_24_MCX_2e_v_3a_64_24_15__Y ? value<4>{0u} : (eq_uu<1>(p_PC, value<32>{0x6u}) ? value<4>{0u} : add_uu<32>(p_PC, value<32>{0x1u}).slice<3,0>().val())));
	// connection
	p_next__inst.next = i_procmux_24_933__Y.curr;
	// connection
	p_line = p_next__inst.curr.concat(i_procmux_24_856__Y).val();
	// connection
	i_flatten_5c_MEM_2e__24_1_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA_5b_41_3a_0_5d__24_31 = i_procmux_24_856__Y;
	// \src: MCX.v:44.12-44.17
	// cell $logic_not$MCX.v:44$12
	i_logic__not_24_MCX_2e_v_3a_44_24_12__Y = logic_not<1>(p_nrst);
	// \src: MCX.v:74.12-74.17
	// cell $logic_not$MCX.v:74$20
	i_logic__not_24_MCX_2e_v_3a_74_24_20__Y = logic_not<1>(p_nrst);
	// \src: MCX.v:86.12-86.17
	// cell $logic_not$MCX.v:86$24
	i_logic__not_24_MCX_2e_v_3a_86_24_24__Y = logic_not<1>(p_nrst);
	// \src: MCX.v:43.5-60.8
	// cell $procdff$983
	if (posedge_p_clk) {
		p_cond = i_procmux_24_856__Y.slice<41,40>().val();
	}
	if (p_nrst == value<1> {0u}) {
		p_cond = value<2>{0u};
	}
	// \src: MCX.v:43.5-60.8
	// cell $procdff$987
	if (posedge_p_clk) {
		p_args_5b_2_5d_ = i_procmux_24_856__Y.slice<11,0>().val();
	}
	if (p_nrst == value<1> {0u}) {
		p_args_5b_2_5d_ = value<12>{0u};
	}
	// connection
	i_mem2bits_24__5c_args_24_MCX_2e_v_3a_38_24_4 = value<12>{0u};
	// connection
	i_mem2bits_24__5c_args_24_MCX_2e_v_3a_38_24_3 = value<12>{0u};
	// connection
	p_i = value<1>{0u};
	// connection
	i_flatten_5c_MEM_2e__24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA = value<42>{0u,0u};
	// connection
	i_flatten_5c_MEM_2e__24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__ADDR = value<3>{0u};
	// connection
	i_0_5c_PC_5b_3_3a_0_5d_ = p_line.slice<45,42>().val();
	// connection
	i_0_5c_cond_5b_1_3a_0_5d_ = p_line.slice<41,40>().val();
	// connection
	i_0_5c_inst_5b_3_3a_0_5d_ = p_line.slice<39,36>().val();
	// connection
	i_0_5c_args_5b_0_5d__5b_11_3a_0_5d_ = p_line.slice<35,24>().val();
	// connection
	i_0_5c_args_5b_1_5d__5b_11_3a_0_5d_ = p_line.slice<23,12>().val();
	// connection
	i_0_5c_args_5b_2_5d__5b_11_3a_0_5d_ = p_line.slice<11,0>().val();
	// connection
	i_0_5c_acc_5b_10_3a_0_5d_ = i_procmux_24_924__Y;
	// connection
	i_0_5c_p0r_5b_6_3a_0_5d_ = p_p0r.curr;
	// connection
	i_0_5c_p0w_5b_6_3a_0_5d_ = i_procmux_24_918__Y.curr;
	// connection
	i_0_5c_p0oe_5b_0_3a_0_5d_ = i_procmux_24_914__Y.curr;
	// connection
	i_0_24_mem2bits_24__5c_args_24_MCX_2e_v_3a_38_24_3_5b_11_3a_0_5d__24_9 = p_args_5b_0_5d_;
	// connection
	i_0_5c_numArgs_5b_0_5d__5b_10_3a_0_5d_ = p_args_5b_0_5d_.slice<10,0>().val();
	// connection
	i_0_24_mem2bits_24__5c_args_24_MCX_2e_v_3a_38_24_4_5b_11_3a_0_5d__24_10 = p_args_5b_1_5d_;
	// connection
	i_0_5c_numArgs_5b_1_5d__5b_10_3a_0_5d_ = p_args_5b_1_5d_.slice<10,0>().val();
	// connection
	i_0_5c_i_5b_0_3a_0_5d_ = value<1>{0u};
	// connection
	i_0_5c_next__inst_5b_3_3a_0_5d_ = i_procmux_24_933__Y.curr;
	// connection
	i_0_24_mem2bits_24__5c_args_24_MCX_2e_v_3a_65_24_5_5b_11_3a_0_5d__24_14 = (i_eq_24_MCX_2e_v_3a_64_24_15__Y ? p_args_5b_0_5d_ : value<12>{0u});
	// connection
	i_flatten_5c_ALU1_2e__5c_UNOT_2e__24_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_910__Y;
	// connection
	i_flatten_5c_ALU1_2e__5c_UMUL_2e__24_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_907__Y;
	// connection
	i_flatten_5c_ALU1_2e__5c_USUB_2e__24_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_898__Y;
	// connection
	i_flatten_5c_ALU1_2e__5c_UADD_2e__24_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_889__Y;
	// connection
	i_flatten_5c_ALU1_2e__24_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_877__Y;
	// connection
	i_flatten_5c_MEM_2e__24_0_5c_mem_5b_0_5d__5b_41_3a_0_5d_ = i_procmux_24_874__Y;
	// connection
	i_flatten_5c_MEM_2e__24_0_5c_mem_5b_1_5d__5b_41_3a_0_5d_ = i_procmux_24_871__Y;
	// connection
	i_flatten_5c_MEM_2e__24_0_5c_mem_5b_2_5d__5b_41_3a_0_5d_ = i_procmux_24_868__Y;
	// connection
	i_flatten_5c_MEM_2e__24_0_5c_mem_5b_3_5d__5b_41_3a_0_5d_ = i_procmux_24_865__Y;
	// connection
	i_flatten_5c_MEM_2e__24_0_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__ADDR_5b_2_3a_0_5d__24_29 = p_next__inst.curr.slice<2,0>().val();
	// connection
	i_flatten_5c_MEM_2e__24_0_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA_5b_41_3a_0_5d__24_30 = i_flatten_5c_MEM_2e__24_1_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA_5b_41_3a_0_5d__24_31;
	// connection
	i_flatten_5c_MEM_2e__24_0_5c_line_5b_45_3a_0_5d_ = p_next__inst.curr.concat(i_flatten_5c_MEM_2e__24_1_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA_5b_41_3a_0_5d__24_31).val();
	// connection
	p_ALU1_2e_arg2 = p_numArgs_5b_1_5d_;
	// connection
	p_p1.next = (p_p1oe ? p_p1w : value<7>{0u});
	// connection
	p_p0.next = (p_p0oe ? p_p0w : value<7>{0u});
	return converged;
}

bool p_MCX::commit() {
	bool changed = false;
	changed |= i_procmux_24_933__Y.commit();
	changed |= i_procmux_24_918__Y.commit();
	changed |= i_procmux_24_914__Y.commit();
	changed |= p_p0r.commit();
	changed |= p_next__inst.commit();
	changed |= p_acc.commit();
	changed |= p_p1.commit();
	changed |= p_p0.commit();
	prev_p_clk = p_clk;
	return changed;
}

void p_MCX::debug_info(debug_items &items, std::string path) {
	assert(path.empty() || path[path.size() - 1] == ' ');
	items.add(path + "MEM addr", debug_item(debug_alias(), p_next__inst, 0));
	items.add(path + "ALU1 acc", debug_item(debug_alias(), p_acc, 0));
	items.add(path + "ALU1 UADD acc", debug_item(debug_alias(), p_acc, 0));
	items.add(path + "ALU1 USUB acc", debug_item(debug_alias(), p_acc, 0));
	items.add(path + "ALU1 UMUL acc", debug_item(debug_alias(), p_acc, 0));
	items.add(path + "ALU1 UNOT acc", debug_item(debug_alias(), p_acc, 0));
	static const value<1> const_p_i = value<1>{0u};
	items.add(path + "i", debug_item(const_p_i, 0));
	items.add(path + "p0r", debug_item(p_p0r, 0));
	items.add(path + "next_inst", debug_item(p_next__inst, 0));
	items.add(path + "acc", debug_item(p_acc, 0));
	items.add(path + "p1", debug_item(p_p1, 0));
	items.add(path + "p0", debug_item(p_p0, 0));
	items.add(path + "nrst", debug_item(p_nrst, 0));
	items.add(path + "clk", debug_item(p_clk, 0));
}

// \cells_not_processed: 1
// \src: alu/add.v:1.1-16.10
struct p_add : public module {
	// \src: alu/add.v:5.21-5.24
	/*output*/ wire<11> p_out;
	// \src: alu/add.v:3.23-3.26
	/*input*/ value<11> p_acc;
	// \src: alu/add.v:2.23-2.27
	/*input*/ value<11> p_arg1;

	bool eval() override;
	bool commit() override;
	void debug_info(debug_items &items, std::string path = "") override;
}; // struct p_add

bool p_add::eval() {
	bool converged = false;
	value<11> i_procmux_24_832__Y;
	// \src: alu/add.v:12.8-12.15
	value<1> i_gt_24_alu_2f_add_2e_v_3a_12_24_36__Y;
	// \src: alu/add.v:11.3-15.6
	value<11> i_0_5c_out_5b_10_3a_0_5d_;
	// \src: alu/add.v:7.22-7.25
	value<12> p_tmp;
	// connection
	p_tmp = add_ss<12>(p_acc, p_arg1);
	// \src: alu/add.v:12.8-12.15
	// cell $gt$alu/add.v:12$36
	i_gt_24_alu_2f_add_2e_v_3a_12_24_36__Y = gt_ss<1>(p_tmp, value<32>{0x3e7u});
	// cells $procmux$829 $procmux$826 $lt$alu/add.v:13$37
	i_procmux_24_832__Y = (i_gt_24_alu_2f_add_2e_v_3a_12_24_36__Y ? value<11>{0x3e7u} : (i_gt_24_alu_2f_add_2e_v_3a_12_24_36__Y ? value<11>{0u} : (lt_ss<1>(p_tmp, value<32>{0xfffffc19u}) ? value<11>{0x419u} : p_tmp.slice<10,0>().val())));
	// connection
	p_out.next = i_procmux_24_832__Y;
	// connection
	i_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_832__Y;
	return converged;
}

bool p_add::commit() {
	bool changed = false;
	changed |= p_out.commit();
	return changed;
}

void p_add::debug_info(debug_items &items, std::string path) {
	assert(path.empty() || path[path.size() - 1] == ' ');
	items.add(path + "out", debug_item(p_out, 0));
	items.add(path + "acc", debug_item(p_acc, 0));
	items.add(path + "arg1", debug_item(p_arg1, 0));
}

// \cells_not_processed: 1
// \src: alu/mul.v:1.1-15.10
struct p_mul : public module {
	// \src: alu/mul.v:5.28-5.31
	/*output*/ wire<11> p_out;
	// \src: alu/mul.v:3.23-3.27
	/*input*/ value<11> p_arg1;
	// \src: alu/mul.v:2.23-2.26
	/*input*/ value<11> p_acc;

	bool eval() override;
	bool commit() override;
	void debug_info(debug_items &items, std::string path = "") override;
}; // struct p_mul

bool p_mul::eval() {
	bool converged = false;
	value<11> i_procmux_24_208__Y;
	// \src: alu/mul.v:11.8-11.17
	value<1> i_gt_24_alu_2f_mul_2e_v_3a_11_24_181__Y;
	// \src: alu/mul.v:10.3-14.6
	value<11> i_0_5c_out_5b_10_3a_0_5d_;
	// \src: alu/mul.v:7.22-7.25
	value<22> p_tmp;
	// connection
	p_tmp = mul_ss<22>(p_acc, p_arg1);
	// \src: alu/mul.v:11.8-11.17
	// cell $gt$alu/mul.v:11$181
	i_gt_24_alu_2f_mul_2e_v_3a_11_24_181__Y = gt_ss<1>(p_tmp, value<32>{0x3e7u});
	// cells $procmux$205 $procmux$202 $lt$alu/mul.v:12$182
	i_procmux_24_208__Y = (i_gt_24_alu_2f_mul_2e_v_3a_11_24_181__Y ? value<11>{0x3e7u} : (i_gt_24_alu_2f_mul_2e_v_3a_11_24_181__Y ? value<11>{0u} : (lt_ss<1>(p_tmp, value<32>{0xfffffc19u}) ? value<11>{0x419u} : p_tmp.slice<10,0>().val())));
	// connection
	p_out.next = i_procmux_24_208__Y;
	// connection
	i_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_208__Y;
	return converged;
}

bool p_mul::commit() {
	bool changed = false;
	changed |= p_out.commit();
	return changed;
}

void p_mul::debug_info(debug_items &items, std::string path) {
	assert(path.empty() || path[path.size() - 1] == ' ');
	items.add(path + "out", debug_item(p_out, 0));
	items.add(path + "arg1", debug_item(p_arg1, 0));
	items.add(path + "acc", debug_item(p_acc, 0));
}

// \cells_not_processed: 1
// \src: alu/dgt.v:1.1-18.10
struct p_dgt : public module {
	wire<1> i_procmux_24_496__Y;
	wire<1> i_procmux_24_472__Y;
	wire<1> i_procmux_24_448__Y;
	wire<1> i_procmux_24_424__Y;
	wire<1> i_procmux_24_400__Y;
	wire<1> i_procmux_24_376__Y;
	wire<1> i_procmux_24_352__Y;
	wire<1> i_procmux_24_328__Y;
	wire<1> i_procmux_24_304__Y;
	wire<1> i_procmux_24_280__Y;
	wire<1> i_procmux_24_256__Y;
	wire<1> i_procmux_24_232__Y;
	// \src: alu/dgt.v:4.29-4.32
	/*output*/ wire<11> p_out;
	// \src: alu/dgt.v:3.23-3.27
	/*input*/ value<11> p_arg1;
	// \src: alu/dgt.v:2.23-2.26
	/*input*/ value<11> p_acc;

	bool eval() override;
	bool commit() override;
	void debug_info(debug_items &items, std::string path = "") override;
}; // struct p_dgt

bool p_dgt::eval() {
	bool converged = false;
	value<11> i_procmux_24_499__Y;
	// \hdlname: UBCD bin
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:1.36-1.39
	value<11> p_UBCD_2e_bin;
	// \hdlname: UBCD bcd
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:1.66-1.69
	value<13> p_UBCD_2e_bcd;
	// \hdlname: UBCD i
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:2.7-2.8
	value<1> p_UBCD_2e_i;
	// \hdlname: UBCD j
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:3.7-3.8
	value<1> p_UBCD_2e_j;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:4.3-12.6
	value<1> i_flatten_5c_UBCD_2e__24_0_5c_i_5b_0_3a_0_5d_;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:4.3-12.6
	value<12> i_flatten_5c_UBCD_2e__24_0_5c_bcd_5b_11_3a_0_5d_;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:4.3-12.6
	value<1> i_flatten_5c_UBCD_2e__24_0_5c_j_5b_0_3a_0_5d_;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_100__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_101__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_102__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_103__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_104__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_105__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_106__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_107__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_108__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_109__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_110__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_111__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_112__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_113__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_114__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_115__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_116__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_117__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_118__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_119__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_120__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_121__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_122__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_123__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_124__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_125__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_126__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_127__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_128__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_129__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_130__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_131__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_132__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_133__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_134__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_135__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_136__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_137__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_138__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_139__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_140__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_141__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_142__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_143__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_144__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_145__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_146__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_147__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_148__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_149__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_150__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_151__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_152__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_153__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_154__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_155__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_156__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_157__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_158__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_159__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_160__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_161__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_162__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_163__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_164__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_165__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_166__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_167__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_168__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_169__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	value<1> i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_170__Y;
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	value<32> i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_171__Y;
	// \src: alu/dgt.v:11.3-16.6
	value<11> i_0_5c_out_5b_10_3a_0_5d_;
	// \src: alu/dgt.v:7.8-7.11
	value<1> p_bin;
	// connection
	p_UBCD_2e_bcd.slice<11,0>() = i_procmux_24_232__Y.curr.concat(i_procmux_24_496__Y.curr).concat(i_procmux_24_256__Y.curr).concat(i_procmux_24_280__Y.curr).concat(i_procmux_24_304__Y.curr).concat(i_procmux_24_328__Y.curr).concat(i_procmux_24_352__Y.curr).concat(i_procmux_24_376__Y.curr).concat(i_procmux_24_400__Y.curr).concat(i_procmux_24_424__Y.curr).concat(i_procmux_24_448__Y.curr).concat(i_procmux_24_472__Y.curr).val();
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$104
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_104__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$100
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_100__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$102
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_102__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$110
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_110__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$105
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_105__Y = add_uu<32>(p_UBCD_2e_bcd.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$106
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_106__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$101
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_101__Y = add_uu<32>(p_UBCD_2e_bcd.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$108
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_108__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$103
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_103__Y = add_uu<32>(p_UBCD_2e_bcd.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$116
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_116__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$111
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_111__Y = add_uu<32>(p_UBCD_2e_bcd.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$112
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_112__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$107
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_107__Y = add_uu<32>(p_UBCD_2e_bcd.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$114
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_114__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$109
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_109__Y = add_uu<32>(p_UBCD_2e_bcd.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$122
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_122__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$117
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_117__Y = add_uu<32>(p_UBCD_2e_bcd.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$118
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_118__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$113
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_113__Y = add_uu<32>(p_UBCD_2e_bcd.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$120
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_120__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$115
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_115__Y = add_uu<32>(p_UBCD_2e_bcd.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$128
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_128__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$123
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_123__Y = add_uu<32>(p_UBCD_2e_bcd.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$124
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_124__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$119
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_119__Y = add_uu<32>(p_UBCD_2e_bcd.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$126
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_126__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$121
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_121__Y = add_uu<32>(p_UBCD_2e_bcd.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$134
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_134__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$129
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_129__Y = add_uu<32>(p_UBCD_2e_bcd.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$130
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_130__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$125
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_125__Y = add_uu<32>(p_UBCD_2e_bcd.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$132
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_132__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$127
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_127__Y = add_uu<32>(p_UBCD_2e_bcd.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$140
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_140__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$135
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_135__Y = add_uu<32>(p_UBCD_2e_bcd.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$136
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_136__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$131
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_131__Y = add_uu<32>(p_UBCD_2e_bcd.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$138
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_138__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$133
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_133__Y = add_uu<32>(p_UBCD_2e_bcd.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$146
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_146__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$141
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_141__Y = add_uu<32>(p_UBCD_2e_bcd.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$142
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_142__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$137
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_137__Y = add_uu<32>(p_UBCD_2e_bcd.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$144
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_144__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$139
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_139__Y = add_uu<32>(p_UBCD_2e_bcd.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$152
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_152__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$147
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_147__Y = add_uu<32>(p_UBCD_2e_bcd.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$148
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_148__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$143
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_143__Y = add_uu<32>(p_UBCD_2e_bcd.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$150
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_150__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$145
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_145__Y = add_uu<32>(p_UBCD_2e_bcd.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$158
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_158__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$153
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_153__Y = add_uu<32>(p_UBCD_2e_bcd.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$154
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_154__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$149
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_149__Y = add_uu<32>(p_UBCD_2e_bcd.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$156
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_156__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$151
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_151__Y = add_uu<32>(p_UBCD_2e_bcd.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$164
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_164__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$159
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_159__Y = add_uu<32>(p_UBCD_2e_bcd.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$160
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_160__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$155
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_155__Y = add_uu<32>(p_UBCD_2e_bcd.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$162
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_162__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$157
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_157__Y = add_uu<32>(p_UBCD_2e_bcd.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$170
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_170__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$165
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_165__Y = add_uu<32>(p_UBCD_2e_bcd.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$166
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_166__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$161
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_161__Y = add_uu<32>(p_UBCD_2e_bcd.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:9.12-9.31
	// cell $flatten\UBCD.$gt$alu/bin2bcd.v:9$168
	i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_168__Y = gt_uu<1>(p_UBCD_2e_bcd.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$163
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_163__Y = add_uu<32>(p_UBCD_2e_bcd.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$171
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_171__Y = add_uu<32>(p_UBCD_2e_bcd.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$167
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_167__Y = add_uu<32>(p_UBCD_2e_bcd.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/dgt.v:9.11-9.37|alu/bin2bcd.v:10.29-10.47
	// cell $flatten\UBCD.$add$alu/bin2bcd.v:10$169
	i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_169__Y = add_uu<32>(p_UBCD_2e_bcd.slice<7,4>().val(), value<32>{0x3u});
	// cells $procmux$494 $procmux$492 $procmux$490 $procmux$488 $procmux$486 $procmux$484 $procmux$482 $procmux$480 $procmux$478 $procmux$476 $procmux$474
	i_procmux_24_496__Y.next = (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_170__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_171__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_164__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_165__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_158__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_159__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_152__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_153__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_146__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_147__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_140__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_141__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_134__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_135__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_128__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_129__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_122__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_123__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_116__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_117__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_110__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_111__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_104__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_105__Y.slice<2>().val() : value<1>{0u}))))))))))));
	// cells $procmux$470 $procmux$468 $procmux$466 $procmux$464 $procmux$462 $procmux$460 $procmux$458 $procmux$456 $procmux$454 $procmux$452 $procmux$450
	i_procmux_24_472__Y.next = (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_166__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_167__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_160__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_161__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_154__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_155__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_148__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_149__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_142__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_143__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_136__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_137__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_130__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_131__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_124__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_125__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_118__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_119__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_112__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_113__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_106__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_107__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_100__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_101__Y.slice<0>().val() : value<1>{0u}))))))))))));
	// cells $procmux$446 $procmux$444 $procmux$442 $procmux$440 $procmux$438 $procmux$436 $procmux$434 $procmux$432 $procmux$430 $procmux$428 $procmux$426
	i_procmux_24_448__Y.next = (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_166__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_167__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_160__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_161__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_154__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_155__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_148__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_149__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_142__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_143__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_136__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_137__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_130__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_131__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_124__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_125__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_118__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_119__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_112__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_113__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_106__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_107__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_100__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_101__Y.slice<1>().val() : value<1>{0u}))))))))))));
	// cells $procmux$422 $procmux$420 $procmux$418 $procmux$416 $procmux$414 $procmux$412 $procmux$410 $procmux$408 $procmux$406 $procmux$404 $procmux$402
	i_procmux_24_424__Y.next = (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_166__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_167__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_160__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_161__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_154__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_155__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_148__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_149__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_142__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_143__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_136__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_137__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_130__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_131__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_124__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_125__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_118__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_119__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_112__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_113__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_106__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_107__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_100__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_101__Y.slice<2>().val() : value<1>{0u}))))))))))));
	// cells $procmux$398 $procmux$396 $procmux$394 $procmux$392 $procmux$390 $procmux$388 $procmux$386 $procmux$384 $procmux$382 $procmux$380 $procmux$378
	i_procmux_24_400__Y.next = (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_166__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_167__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_160__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_161__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_154__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_155__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_148__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_149__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_142__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_143__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_136__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_137__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_130__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_131__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_124__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_125__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_118__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_119__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_112__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_113__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_106__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_107__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_100__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_101__Y.slice<3>().val() : value<1>{0u}))))))))))));
	// cells $procmux$374 $procmux$372 $procmux$370 $procmux$368 $procmux$366 $procmux$364 $procmux$362 $procmux$360 $procmux$358 $procmux$356 $procmux$354
	i_procmux_24_376__Y.next = (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_168__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_169__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_162__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_163__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_156__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_157__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_150__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_151__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_144__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_145__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_138__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_139__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_132__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_133__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_126__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_127__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_120__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_121__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_114__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_115__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_108__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_109__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_102__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_103__Y.slice<0>().val() : value<1>{0u}))))))))))));
	// cells $procmux$350 $procmux$348 $procmux$346 $procmux$344 $procmux$342 $procmux$340 $procmux$338 $procmux$336 $procmux$334 $procmux$332 $procmux$330
	i_procmux_24_352__Y.next = (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_168__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_169__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_162__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_163__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_156__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_157__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_150__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_151__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_144__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_145__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_138__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_139__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_132__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_133__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_126__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_127__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_120__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_121__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_114__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_115__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_108__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_109__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_102__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_103__Y.slice<1>().val() : value<1>{0u}))))))))))));
	// cells $procmux$326 $procmux$324 $procmux$322 $procmux$320 $procmux$318 $procmux$316 $procmux$314 $procmux$312 $procmux$310 $procmux$308 $procmux$306
	i_procmux_24_328__Y.next = (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_168__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_169__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_162__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_163__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_156__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_157__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_150__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_151__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_144__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_145__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_138__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_139__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_132__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_133__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_126__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_127__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_120__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_121__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_114__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_115__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_108__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_109__Y.slice<2>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_102__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_103__Y.slice<2>().val() : value<1>{0u}))))))))))));
	// cells $procmux$302 $procmux$300 $procmux$298 $procmux$296 $procmux$294 $procmux$292 $procmux$290 $procmux$288 $procmux$286 $procmux$284 $procmux$282
	i_procmux_24_304__Y.next = (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_168__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_169__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_162__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_163__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_156__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_157__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_150__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_151__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_144__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_145__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_138__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_139__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_132__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_133__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_126__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_127__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_120__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_121__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_114__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_115__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_108__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_109__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_102__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_103__Y.slice<3>().val() : value<1>{0u}))))))))))));
	// cells $procmux$278 $procmux$276 $procmux$274 $procmux$272 $procmux$270 $procmux$268 $procmux$266 $procmux$264 $procmux$262 $procmux$260 $procmux$258
	i_procmux_24_280__Y.next = (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_170__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_171__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_164__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_165__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_158__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_159__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_152__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_153__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_146__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_147__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_140__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_141__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_134__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_135__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_128__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_129__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_122__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_123__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_116__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_117__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_110__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_111__Y.slice<0>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_104__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_105__Y.slice<0>().val() : value<1>{0u}))))))))))));
	// cells $procmux$254 $procmux$252 $procmux$250 $procmux$248 $procmux$246 $procmux$244 $procmux$242 $procmux$240 $procmux$238 $procmux$236 $procmux$234
	i_procmux_24_256__Y.next = (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_170__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_171__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_164__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_165__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_158__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_159__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_152__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_153__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_146__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_147__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_140__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_141__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_134__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_135__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_128__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_129__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_122__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_123__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_116__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_117__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_110__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_111__Y.slice<1>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_104__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_105__Y.slice<1>().val() : value<1>{0u}))))))))))));
	// cells $procmux$230 $procmux$228 $procmux$226 $procmux$224 $procmux$222 $procmux$220 $procmux$218 $procmux$216 $procmux$214 $procmux$212 $procmux$210
	i_procmux_24_232__Y.next = (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_170__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_171__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_164__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_165__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_158__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_159__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_152__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_153__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_146__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_147__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_140__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_141__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_134__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_135__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_128__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_129__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_122__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_123__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_116__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_117__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_110__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_111__Y.slice<3>().val() : (i_flatten_5c_UBCD_2e__24_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_104__Y ? i_flatten_5c_UBCD_2e__24_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_105__Y.slice<3>().val() : value<1>{0u}))))))))))));
	// cells $logic_and$alu/dgt.v:12$175 $lt$alu/dgt.v:12$174 $gt$alu/dgt.v:12$173 $shiftx$alu/dgt.v:0$178 $add$alu/dgt.v:0$177 $mul$alu/dgt.v:13$176
	i_procmux_24_499__Y = (logic_and<1>(gt_ss<1>(p_arg1, value<32>{0u}), lt_ss<1>(p_arg1, value<32>{0x3u})) ? value<7>{0u}.concat(shiftx_us<4>(p_UBCD_2e_bcd.slice<0>().val(), add_ss<32>(mul_ss<32>(value<32>{0x4u}, p_arg1), value<32>{0u}))).val() : value<11>{0x3e7u});
	// connection
	p_out.next = i_procmux_24_499__Y;
	// connection
	p_UBCD_2e_j = value<1>{0x1u};
	// connection
	p_UBCD_2e_i = value<1>{0u};
	// connection
	i_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_499__Y;
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_bcd_5b_11_3a_0_5d_.slice<10>() = i_procmux_24_496__Y.curr;
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_bcd_5b_11_3a_0_5d_.slice<0>() = i_procmux_24_472__Y.curr;
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_bcd_5b_11_3a_0_5d_.slice<1>() = i_procmux_24_448__Y.curr;
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_bcd_5b_11_3a_0_5d_.slice<2>() = i_procmux_24_424__Y.curr;
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_bcd_5b_11_3a_0_5d_.slice<3>() = i_procmux_24_400__Y.curr;
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_bcd_5b_11_3a_0_5d_.slice<4>() = i_procmux_24_376__Y.curr;
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_bcd_5b_11_3a_0_5d_.slice<5>() = i_procmux_24_352__Y.curr;
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_bcd_5b_11_3a_0_5d_.slice<6>() = i_procmux_24_328__Y.curr;
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_bcd_5b_11_3a_0_5d_.slice<7>() = i_procmux_24_304__Y.curr;
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_bcd_5b_11_3a_0_5d_.slice<8>() = i_procmux_24_280__Y.curr;
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_bcd_5b_11_3a_0_5d_.slice<9>() = i_procmux_24_256__Y.curr;
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_bcd_5b_11_3a_0_5d_.slice<11>() = i_procmux_24_232__Y.curr;
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_j_5b_0_3a_0_5d_ = value<1>{0x1u};
	// connection
	i_flatten_5c_UBCD_2e__24_0_5c_i_5b_0_3a_0_5d_ = value<1>{0u};
	// connection
	p_UBCD_2e_bin = p_acc;
	return converged;
}

bool p_dgt::commit() {
	bool changed = false;
	changed |= i_procmux_24_496__Y.commit();
	changed |= i_procmux_24_472__Y.commit();
	changed |= i_procmux_24_448__Y.commit();
	changed |= i_procmux_24_424__Y.commit();
	changed |= i_procmux_24_400__Y.commit();
	changed |= i_procmux_24_376__Y.commit();
	changed |= i_procmux_24_352__Y.commit();
	changed |= i_procmux_24_328__Y.commit();
	changed |= i_procmux_24_304__Y.commit();
	changed |= i_procmux_24_280__Y.commit();
	changed |= i_procmux_24_256__Y.commit();
	changed |= i_procmux_24_232__Y.commit();
	changed |= p_out.commit();
	return changed;
}

void p_dgt::debug_info(debug_items &items, std::string path) {
	assert(path.empty() || path[path.size() - 1] == ' ');
	static const value<1> const_p_UBCD_2e_i = value<1>{0u};
	items.add(path + "UBCD i", debug_item(const_p_UBCD_2e_i, 0));
	static const value<1> const_p_UBCD_2e_j = value<1>{0x1u};
	items.add(path + "UBCD j", debug_item(const_p_UBCD_2e_j, 0));
	items.add(path + "out", debug_item(p_out, 0));
	items.add(path + "arg1", debug_item(p_arg1, 0));
	items.add(path + "acc", debug_item(p_acc, 0));
}

// \cells_not_processed: 1
// \src: prog_mem.v:1.1-30.10
struct p_prog__mem : public module {
	// \src: prog_mem.v:4.23-4.27
	/*output*/ wire<46> p_line;
	// \src: prog_mem.v:3.17-3.21
	/*input*/ value<4> p_addr;
	// \src: prog_mem.v:2.11-2.14
	/*input*/ value<1> p_rst;

	bool eval() override;
	bool commit() override;
	void debug_info(debug_items &items, std::string path = "") override;
}; // struct p_prog__mem

bool p_prog__mem::eval() {
	bool converged = false;
	value<1> i_auto_24_rtlil_2e_cc_3a_2125_3a_ReduceOr_24_945;
	value<42> i_procmux_24_847__Y;
	value<42> i_procmux_24_844__Y;
	value<42> i_procmux_24_841__Y;
	value<42> i_procmux_24_838__Y;
	value<42> i_procmux_24_835__Y;
	// \src: prog_mem.v:14.12-14.16
	value<1> i_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y;
	// \src: prog_mem.v:13.5-29.8
	value<42> i_0_5c_mem_5b_3_5d__5b_41_3a_0_5d_;
	// \src: prog_mem.v:13.5-29.8
	value<42> i_0_5c_mem_5b_2_5d__5b_41_3a_0_5d_;
	// \src: prog_mem.v:13.5-29.8
	value<42> i_0_5c_mem_5b_1_5d__5b_41_3a_0_5d_;
	// \src: prog_mem.v:13.5-29.8
	value<42> i_0_5c_mem_5b_0_5d__5b_41_3a_0_5d_;
	// \src: prog_mem.v:8.5-10.8
	value<42> i_1_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA_5b_41_3a_0_5d__24_31;
	// \src: prog_mem.v:8.5-10.8
	value<42> i_0_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA_5b_41_3a_0_5d__24_30;
	// \src: prog_mem.v:8.5-10.8
	value<3> i_0_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__ADDR_5b_2_3a_0_5d__24_29;
	// \src: prog_mem.v:8.5-10.8
	value<46> i_0_5c_line_5b_45_3a_0_5d_;
	// \nosync: 1
	// \src: prog_mem.v:0.0-0.0
	value<42> i_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA;
	// \nosync: 1
	// \src: prog_mem.v:0.0-0.0
	value<3> i_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__ADDR;
	// \src: prog_mem.v:6.16-6.19
	value<42> p_mem_5b_6_5d_;
	// \src: prog_mem.v:6.16-6.19
	value<42> p_mem_5b_5_5d_;
	// \src: prog_mem.v:6.16-6.19
	value<42> p_mem_5b_4_5d_;
	// \src: prog_mem.v:6.16-6.19
	value<42> p_mem_5b_3_5d_;
	// \src: prog_mem.v:6.16-6.19
	value<42> p_mem_5b_2_5d_;
	// \src: prog_mem.v:6.16-6.19
	value<42> p_mem_5b_1_5d_;
	// \src: prog_mem.v:6.16-6.19
	value<42> p_mem_5b_0_5d_;
	// \src: prog_mem.v:14.12-14.16
	// cell $logic_not$prog_mem.v:14$33
	i_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y = logic_not<1>(p_rst);
	// cells $auto$proc_dlatch.cc:257:make_hold$942 $auto$proc_dlatch.cc:253:make_hold$940 $auto$proc_dlatch.cc:244:make_hold$938
	i_auto_24_rtlil_2e_cc_3a_2125_3a_ReduceOr_24_945 = reduce_or<1>(and_uu<1>(not_u<1>(i_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y), reduce_or<1>(value<1>{0x1u})));
	// \full_case: 1
	// \src: prog_mem.v:14.12-14.16|prog_mem.v:14.9-28.12
	// cell $procmux$835
	i_procmux_24_835__Y = (i_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y ? value<42>{0x1000000u,0x20u} : value<42>{0x1000000u,0x20u});
	// \full_case: 1
	// \src: prog_mem.v:14.12-14.16|prog_mem.v:14.9-28.12
	// cell $procmux$838
	i_procmux_24_838__Y = (i_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y ? value<42>{0u,0x80u} : value<42>{0u,0x80u});
	// \full_case: 1
	// \src: prog_mem.v:14.12-14.16|prog_mem.v:14.9-28.12
	// cell $procmux$841
	i_procmux_24_841__Y = (i_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y ? value<42>{0u,0u} : value<42>{0u,0u});
	// \full_case: 1
	// \src: prog_mem.v:14.12-14.16|prog_mem.v:14.9-28.12
	// cell $procmux$844
	i_procmux_24_844__Y = (i_logic__not_24_prog__mem_2e_v_3a_14_24_33__Y ? value<42>{0x96801000u,0x10u} : value<42>{0x96801000u,0x10u});
	// \src: prog_mem.v:13.5-29.8
	// cell $auto$proc_dlatch.cc:430:proc_dlatch$957
	if (not_u<1>(i_auto_24_rtlil_2e_cc_3a_2125_3a_ReduceOr_24_945) == value<1> {1u}) {
		p_mem_5b_3_5d_ = i_procmux_24_835__Y;
	}
	// \src: prog_mem.v:13.5-29.8
	// cell $auto$proc_dlatch.cc:430:proc_dlatch$954
	if (not_u<1>(i_auto_24_rtlil_2e_cc_3a_2125_3a_ReduceOr_24_945) == value<1> {1u}) {
		p_mem_5b_2_5d_ = i_procmux_24_838__Y;
	}
	// \src: prog_mem.v:13.5-29.8
	// cell $auto$proc_dlatch.cc:430:proc_dlatch$951
	if (not_u<1>(i_auto_24_rtlil_2e_cc_3a_2125_3a_ReduceOr_24_945) == value<1> {1u}) {
		p_mem_5b_1_5d_ = i_procmux_24_841__Y;
	}
	// \src: prog_mem.v:13.5-29.8
	// cell $auto$proc_dlatch.cc:430:proc_dlatch$948
	if (not_u<1>(i_auto_24_rtlil_2e_cc_3a_2125_3a_ReduceOr_24_945) == value<1> {1u}) {
		p_mem_5b_0_5d_ = i_procmux_24_844__Y;
	}
	// cells $procmux$848_CMP0 $procmux$849_CMP0 $procmux$850_CMP0 $procmux$851_CMP0 $procmux$852_CMP0 $procmux$853_CMP0 $procmux$854_CMP0
	i_procmux_24_847__Y = (eq_uu<1>(p_addr.slice<2,0>().val(), value<3>{0x6u}) ? p_mem_5b_6_5d_ : (eq_uu<1>(p_addr.slice<2,0>().val(), value<3>{0x5u}) ? p_mem_5b_5_5d_ : (eq_uu<1>(p_addr.slice<2,0>().val(), value<3>{0x4u}) ? p_mem_5b_4_5d_ : (eq_uu<1>(p_addr.slice<2,0>().val(), value<3>{0x3u}) ? p_mem_5b_3_5d_ : (eq_uu<1>(p_addr.slice<2,0>().val(), value<3>{0x2u}) ? p_mem_5b_2_5d_ : (eq_uu<1>(p_addr.slice<2,0>().val(), value<3>{0x1u}) ? p_mem_5b_1_5d_ : (eq_uu<1>(p_addr.slice<2,0>().val(), value<3>{0u}) ? p_mem_5b_0_5d_ : value<42>{0u,0u})))))));
	// connection
	i_1_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA_5b_41_3a_0_5d__24_31 = i_procmux_24_847__Y;
	// connection
	i_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA = value<42>{0u,0u};
	// connection
	i_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__ADDR = value<3>{0u};
	// connection
	p_line.next = p_addr.concat(i_procmux_24_847__Y).val();
	// connection
	i_0_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__ADDR_5b_2_3a_0_5d__24_29 = p_addr.slice<2,0>().val();
	// connection
	i_0_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA_5b_41_3a_0_5d__24_30 = i_1_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA_5b_41_3a_0_5d__24_31;
	// connection
	i_0_5c_line_5b_45_3a_0_5d_ = p_addr.concat(i_1_24_mem2reg__rd_24__5c_mem_24_prog__mem_2e_v_3a_9_24_27__DATA_5b_41_3a_0_5d__24_31).val();
	// connection
	i_0_5c_mem_5b_0_5d__5b_41_3a_0_5d_ = i_procmux_24_844__Y;
	// connection
	i_0_5c_mem_5b_1_5d__5b_41_3a_0_5d_ = i_procmux_24_841__Y;
	// connection
	i_0_5c_mem_5b_2_5d__5b_41_3a_0_5d_ = i_procmux_24_838__Y;
	// connection
	i_0_5c_mem_5b_3_5d__5b_41_3a_0_5d_ = i_procmux_24_835__Y;
	return converged;
}

bool p_prog__mem::commit() {
	bool changed = false;
	changed |= p_line.commit();
	return changed;
}

void p_prog__mem::debug_info(debug_items &items, std::string path) {
	assert(path.empty() || path[path.size() - 1] == ' ');
	items.add(path + "line", debug_item(p_line, 0));
	items.add(path + "addr", debug_item(p_addr, 0));
	items.add(path + "rst", debug_item(p_rst, 0));
}

// \cells_not_processed: 1
// \src: alu/alu.v:7.1-34.10
struct p_alu : public module {
	// \src: alu/alu.v:10.21-10.24
	/*output*/ wire<11> p_out;
	// \src: alu/alu.v:9.33-9.36
	/*input*/ value<11> p_acc;
	// \src: alu/alu.v:9.27-9.31
	/*input*/ value<11> p_arg2;
	// \src: alu/alu.v:9.21-9.25
	/*input*/ value<11> p_arg1;
	// \src: alu/alu.v:8.20-8.24
	/*input*/ value<4> p_inst;

	bool eval() override;
	bool commit() override;
	void debug_info(debug_items &items, std::string path = "") override;
}; // struct p_alu

bool p_alu::eval() {
	bool converged = false;
	value<11> i_procmux_24_820__Y;
	value<11> i_procmux_24_817__Y;
	value<11> i_procmux_24_808__Y;
	value<11> i_procmux_24_799__Y;
	value<11> i_procmux_24_790__Y;
	// \src: alu/alu.v:19.9-19.39|alu/notop.v:5.3-11.6
	value<11> i_flatten_5c_UNOT_2e__24_0_5c_out_5b_10_3a_0_5d_;
	// \hdlname: UMUL tmp
	// \src: alu/alu.v:18.7-18.50|alu/mul.v:7.22-7.25
	value<22> p_UMUL_2e_tmp;
	// \src: alu/alu.v:18.7-18.50|alu/mul.v:10.3-14.6
	value<11> i_flatten_5c_UMUL_2e__24_0_5c_out_5b_10_3a_0_5d_;
	// \src: alu/alu.v:18.7-18.50|alu/mul.v:11.8-11.17
	value<1> i_flatten_5c_UMUL_2e__24_gt_24_alu_2f_mul_2e_v_3a_11_24_181__Y;
	// \hdlname: USUB tmp
	// \src: alu/alu.v:17.7-17.50|alu/sub.v:5.22-5.25
	value<12> p_USUB_2e_tmp;
	// \src: alu/alu.v:17.7-17.50|alu/sub.v:9.3-13.6
	value<11> i_flatten_5c_USUB_2e__24_0_5c_out_5b_10_3a_0_5d_;
	// \src: alu/alu.v:17.7-17.50|alu/sub.v:10.8-10.15
	value<1> i_flatten_5c_USUB_2e__24_gt_24_alu_2f_sub_2e_v_3a_10_24_187__Y;
	// \hdlname: UADD tmp
	// \src: alu/alu.v:16.7-16.50|alu/add.v:7.22-7.25
	value<12> p_UADD_2e_tmp;
	// \src: alu/alu.v:16.7-16.50|alu/add.v:11.3-15.6
	value<11> i_flatten_5c_UADD_2e__24_0_5c_out_5b_10_3a_0_5d_;
	// \src: alu/alu.v:16.7-16.50|alu/add.v:12.8-12.15
	value<1> i_flatten_5c_UADD_2e__24_gt_24_alu_2f_add_2e_v_3a_12_24_36__Y;
	// \src: alu/alu.v:23.3-33.6
	value<11> i_0_5c_out_5b_10_3a_0_5d_;
	// connection
	p_UADD_2e_tmp = add_ss<12>(p_acc, p_arg1);
	// connection
	p_USUB_2e_tmp = sub_ss<12>(p_acc, p_arg1);
	// connection
	p_UMUL_2e_tmp = mul_ss<22>(p_acc, p_arg1);
	// \src: alu/alu.v:16.7-16.50|alu/add.v:12.8-12.15
	// cell $flatten\UADD.$gt$alu/add.v:12$36
	i_flatten_5c_UADD_2e__24_gt_24_alu_2f_add_2e_v_3a_12_24_36__Y = gt_ss<1>(p_UADD_2e_tmp, value<32>{0x3e7u});
	// \src: alu/alu.v:17.7-17.50|alu/sub.v:10.8-10.15
	// cell $flatten\USUB.$gt$alu/sub.v:10$187
	i_flatten_5c_USUB_2e__24_gt_24_alu_2f_sub_2e_v_3a_10_24_187__Y = gt_ss<1>(p_USUB_2e_tmp, value<32>{0x3e7u});
	// \src: alu/alu.v:18.7-18.50|alu/mul.v:11.8-11.17
	// cell $flatten\UMUL.$gt$alu/mul.v:11$181
	i_flatten_5c_UMUL_2e__24_gt_24_alu_2f_mul_2e_v_3a_11_24_181__Y = gt_ss<1>(p_UMUL_2e_tmp, value<32>{0x3e7u});
	// cells $procmux$814 $procmux$811 $flatten\UADD.$lt$alu/add.v:13$37
	i_procmux_24_817__Y = (i_flatten_5c_UADD_2e__24_gt_24_alu_2f_add_2e_v_3a_12_24_36__Y ? value<11>{0x3e7u} : (i_flatten_5c_UADD_2e__24_gt_24_alu_2f_add_2e_v_3a_12_24_36__Y ? value<11>{0u} : (lt_ss<1>(p_UADD_2e_tmp, value<32>{0xfffffc19u}) ? value<11>{0x419u} : p_UADD_2e_tmp.slice<10,0>().val())));
	// cells $procmux$805 $procmux$802 $flatten\USUB.$lt$alu/sub.v:11$188
	i_procmux_24_808__Y = (i_flatten_5c_USUB_2e__24_gt_24_alu_2f_sub_2e_v_3a_10_24_187__Y ? value<11>{0x3e7u} : (i_flatten_5c_USUB_2e__24_gt_24_alu_2f_sub_2e_v_3a_10_24_187__Y ? value<11>{0u} : (lt_ss<1>(p_USUB_2e_tmp, value<32>{0xfffffc19u}) ? value<11>{0x419u} : p_USUB_2e_tmp.slice<10,0>().val())));
	// cells $procmux$796 $procmux$793 $flatten\UMUL.$lt$alu/mul.v:12$182
	i_procmux_24_799__Y = (i_flatten_5c_UMUL_2e__24_gt_24_alu_2f_mul_2e_v_3a_11_24_181__Y ? value<11>{0x3e7u} : (i_flatten_5c_UMUL_2e__24_gt_24_alu_2f_mul_2e_v_3a_11_24_181__Y ? value<11>{0u} : (lt_ss<1>(p_UMUL_2e_tmp, value<32>{0xfffffc19u}) ? value<11>{0x419u} : p_UMUL_2e_tmp.slice<10,0>().val())));
	// cells $flatten\UNOT.$eq$alu/notop.v:7$184
	i_procmux_24_790__Y = (eq_ss<1>(p_acc, value<32>{0u}) ? value<11>{0x64u} : value<11>{0u});
	// cells $procmux$821_CMP0 $procmux$822_CMP0 $procmux$823_CMP0 $procmux$824_CMP0
	i_procmux_24_820__Y = (eq_uu<1>(p_inst, value<4>{0x8u}) ? i_procmux_24_790__Y : (eq_uu<1>(p_inst, value<4>{0x7u}) ? i_procmux_24_799__Y : (eq_uu<1>(p_inst, value<4>{0x6u}) ? i_procmux_24_808__Y : (eq_uu<1>(p_inst, value<4>{0x5u}) ? i_procmux_24_817__Y : p_acc))));
	// connection
	p_out.next = i_procmux_24_820__Y;
	// connection
	i_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_820__Y;
	// connection
	i_flatten_5c_UADD_2e__24_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_817__Y;
	// connection
	i_flatten_5c_USUB_2e__24_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_808__Y;
	// connection
	i_flatten_5c_UMUL_2e__24_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_799__Y;
	// connection
	i_flatten_5c_UNOT_2e__24_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_790__Y;
	return converged;
}

bool p_alu::commit() {
	bool changed = false;
	changed |= p_out.commit();
	return changed;
}

void p_alu::debug_info(debug_items &items, std::string path) {
	assert(path.empty() || path[path.size() - 1] == ' ');
	items.add(path + "out", debug_item(p_out, 0));
	items.add(path + "acc", debug_item(p_acc, 0));
	items.add(path + "arg2", debug_item(p_arg2, 0));
	items.add(path + "arg1", debug_item(p_arg1, 0));
	items.add(path + "inst", debug_item(p_inst, 0));
}

// \cells_not_processed: 1
// \src: alu/bin2bcd.v:1.1-13.10
struct p_bin2bcd : public module {
	wire<1> i_procmux_24_787__Y;
	wire<1> i_procmux_24_763__Y;
	wire<1> i_procmux_24_739__Y;
	wire<1> i_procmux_24_715__Y;
	wire<1> i_procmux_24_691__Y;
	wire<1> i_procmux_24_667__Y;
	wire<1> i_procmux_24_643__Y;
	wire<1> i_procmux_24_619__Y;
	wire<1> i_procmux_24_595__Y;
	wire<1> i_procmux_24_571__Y;
	wire<1> i_procmux_24_547__Y;
	wire<1> i_procmux_24_523__Y;
	// \src: alu/bin2bcd.v:1.66-1.69
	/*output*/ wire<13> p_bcd;
	// \src: alu/bin2bcd.v:1.36-1.39
	/*input*/ value<11> p_bin;

	bool eval() override;
	bool commit() override;
	void debug_info(debug_items &items, std::string path = "") override;
}; // struct p_bin2bcd

bool p_bin2bcd::eval() {
	bool converged = false;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_171__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_170__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_169__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_168__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_167__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_166__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_165__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_164__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_163__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_162__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_161__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_160__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_159__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_158__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_157__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_156__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_155__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_154__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_153__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_152__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_151__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_150__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_149__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_148__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_147__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_146__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_145__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_144__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_143__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_142__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_141__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_140__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_139__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_138__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_137__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_136__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_135__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_134__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_133__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_132__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_131__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_130__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_129__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_128__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_127__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_126__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_125__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_124__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_123__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_122__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_121__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_120__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_119__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_118__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_117__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_116__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_115__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_114__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_113__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_112__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_111__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_110__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_109__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_108__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_107__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_106__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_105__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_104__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_103__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_102__Y;
	// \src: alu/bin2bcd.v:10.29-10.47
	value<32> i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_101__Y;
	// \src: alu/bin2bcd.v:9.12-9.31
	value<1> i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_100__Y;
	// \src: alu/bin2bcd.v:4.3-12.6
	value<1> i_0_5c_j_5b_0_3a_0_5d_;
	// \src: alu/bin2bcd.v:4.3-12.6
	value<12> i_0_5c_bcd_5b_11_3a_0_5d_;
	// \src: alu/bin2bcd.v:4.3-12.6
	value<1> i_0_5c_i_5b_0_3a_0_5d_;
	// \src: alu/bin2bcd.v:3.7-3.8
	value<1> p_j;
	// \src: alu/bin2bcd.v:2.7-2.8
	value<1> p_i;
	// connection
	p_bcd.next.slice<11,0>() = i_procmux_24_523__Y.curr.concat(i_procmux_24_787__Y.curr).concat(i_procmux_24_547__Y.curr).concat(i_procmux_24_571__Y.curr).concat(i_procmux_24_595__Y.curr).concat(i_procmux_24_619__Y.curr).concat(i_procmux_24_643__Y.curr).concat(i_procmux_24_667__Y.curr).concat(i_procmux_24_691__Y.curr).concat(i_procmux_24_715__Y.curr).concat(i_procmux_24_739__Y.curr).concat(i_procmux_24_763__Y.curr).val();
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$104
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_104__Y = gt_uu<1>(p_bcd.curr.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$100
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_100__Y = gt_uu<1>(p_bcd.curr.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$102
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_102__Y = gt_uu<1>(p_bcd.curr.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$110
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_110__Y = gt_uu<1>(p_bcd.curr.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$105
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_105__Y = add_uu<32>(p_bcd.curr.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$106
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_106__Y = gt_uu<1>(p_bcd.curr.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$101
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_101__Y = add_uu<32>(p_bcd.curr.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$108
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_108__Y = gt_uu<1>(p_bcd.curr.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$103
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_103__Y = add_uu<32>(p_bcd.curr.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$116
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_116__Y = gt_uu<1>(p_bcd.curr.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$111
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_111__Y = add_uu<32>(p_bcd.curr.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$112
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_112__Y = gt_uu<1>(p_bcd.curr.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$107
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_107__Y = add_uu<32>(p_bcd.curr.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$114
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_114__Y = gt_uu<1>(p_bcd.curr.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$109
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_109__Y = add_uu<32>(p_bcd.curr.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$122
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_122__Y = gt_uu<1>(p_bcd.curr.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$117
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_117__Y = add_uu<32>(p_bcd.curr.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$118
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_118__Y = gt_uu<1>(p_bcd.curr.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$113
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_113__Y = add_uu<32>(p_bcd.curr.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$120
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_120__Y = gt_uu<1>(p_bcd.curr.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$115
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_115__Y = add_uu<32>(p_bcd.curr.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$128
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_128__Y = gt_uu<1>(p_bcd.curr.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$123
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_123__Y = add_uu<32>(p_bcd.curr.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$124
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_124__Y = gt_uu<1>(p_bcd.curr.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$119
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_119__Y = add_uu<32>(p_bcd.curr.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$126
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_126__Y = gt_uu<1>(p_bcd.curr.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$121
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_121__Y = add_uu<32>(p_bcd.curr.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$134
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_134__Y = gt_uu<1>(p_bcd.curr.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$129
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_129__Y = add_uu<32>(p_bcd.curr.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$130
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_130__Y = gt_uu<1>(p_bcd.curr.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$125
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_125__Y = add_uu<32>(p_bcd.curr.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$132
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_132__Y = gt_uu<1>(p_bcd.curr.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$127
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_127__Y = add_uu<32>(p_bcd.curr.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$140
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_140__Y = gt_uu<1>(p_bcd.curr.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$135
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_135__Y = add_uu<32>(p_bcd.curr.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$136
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_136__Y = gt_uu<1>(p_bcd.curr.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$131
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_131__Y = add_uu<32>(p_bcd.curr.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$138
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_138__Y = gt_uu<1>(p_bcd.curr.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$133
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_133__Y = add_uu<32>(p_bcd.curr.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$146
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_146__Y = gt_uu<1>(p_bcd.curr.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$141
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_141__Y = add_uu<32>(p_bcd.curr.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$142
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_142__Y = gt_uu<1>(p_bcd.curr.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$137
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_137__Y = add_uu<32>(p_bcd.curr.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$144
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_144__Y = gt_uu<1>(p_bcd.curr.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$139
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_139__Y = add_uu<32>(p_bcd.curr.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$152
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_152__Y = gt_uu<1>(p_bcd.curr.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$147
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_147__Y = add_uu<32>(p_bcd.curr.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$148
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_148__Y = gt_uu<1>(p_bcd.curr.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$143
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_143__Y = add_uu<32>(p_bcd.curr.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$150
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_150__Y = gt_uu<1>(p_bcd.curr.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$145
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_145__Y = add_uu<32>(p_bcd.curr.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$158
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_158__Y = gt_uu<1>(p_bcd.curr.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$153
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_153__Y = add_uu<32>(p_bcd.curr.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$154
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_154__Y = gt_uu<1>(p_bcd.curr.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$149
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_149__Y = add_uu<32>(p_bcd.curr.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$156
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_156__Y = gt_uu<1>(p_bcd.curr.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$151
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_151__Y = add_uu<32>(p_bcd.curr.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$164
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_164__Y = gt_uu<1>(p_bcd.curr.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$159
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_159__Y = add_uu<32>(p_bcd.curr.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$160
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_160__Y = gt_uu<1>(p_bcd.curr.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$155
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_155__Y = add_uu<32>(p_bcd.curr.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$162
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_162__Y = gt_uu<1>(p_bcd.curr.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$157
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_157__Y = add_uu<32>(p_bcd.curr.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$170
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_170__Y = gt_uu<1>(p_bcd.curr.slice<11,9>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$165
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_165__Y = add_uu<32>(p_bcd.curr.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$166
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_166__Y = gt_uu<1>(p_bcd.curr.slice<3,1>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$161
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_161__Y = add_uu<32>(p_bcd.curr.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:9.12-9.31
	// cell $gt$alu/bin2bcd.v:9$168
	i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_168__Y = gt_uu<1>(p_bcd.curr.slice<7,5>().val(), value<32>{0x4u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$163
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_163__Y = add_uu<32>(p_bcd.curr.slice<7,4>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$171
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_171__Y = add_uu<32>(p_bcd.curr.slice<11,8>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$167
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_167__Y = add_uu<32>(p_bcd.curr.slice<3,0>().val(), value<32>{0x3u});
	// \src: alu/bin2bcd.v:10.29-10.47
	// cell $add$alu/bin2bcd.v:10$169
	i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_169__Y = add_uu<32>(p_bcd.curr.slice<7,4>().val(), value<32>{0x3u});
	// cells $procmux$785 $procmux$783 $procmux$781 $procmux$779 $procmux$777 $procmux$775 $procmux$773 $procmux$771 $procmux$769 $procmux$767 $procmux$765
	i_procmux_24_787__Y.next = (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_170__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_171__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_164__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_165__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_158__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_159__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_152__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_153__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_146__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_147__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_140__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_141__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_134__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_135__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_128__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_129__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_122__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_123__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_116__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_117__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_110__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_111__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_104__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_105__Y.slice<2>().val() : value<1>{0u}))))))))))));
	// cells $procmux$761 $procmux$759 $procmux$757 $procmux$755 $procmux$753 $procmux$751 $procmux$749 $procmux$747 $procmux$745 $procmux$743 $procmux$741
	i_procmux_24_763__Y.next = (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_166__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_167__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_160__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_161__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_154__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_155__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_148__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_149__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_142__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_143__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_136__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_137__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_130__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_131__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_124__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_125__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_118__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_119__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_112__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_113__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_106__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_107__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_100__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_101__Y.slice<0>().val() : value<1>{0u}))))))))))));
	// cells $procmux$737 $procmux$735 $procmux$733 $procmux$731 $procmux$729 $procmux$727 $procmux$725 $procmux$723 $procmux$721 $procmux$719 $procmux$717
	i_procmux_24_739__Y.next = (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_166__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_167__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_160__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_161__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_154__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_155__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_148__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_149__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_142__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_143__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_136__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_137__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_130__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_131__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_124__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_125__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_118__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_119__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_112__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_113__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_106__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_107__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_100__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_101__Y.slice<1>().val() : value<1>{0u}))))))))))));
	// cells $procmux$713 $procmux$711 $procmux$709 $procmux$707 $procmux$705 $procmux$703 $procmux$701 $procmux$699 $procmux$697 $procmux$695 $procmux$693
	i_procmux_24_715__Y.next = (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_166__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_167__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_160__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_161__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_154__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_155__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_148__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_149__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_142__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_143__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_136__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_137__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_130__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_131__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_124__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_125__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_118__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_119__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_112__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_113__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_106__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_107__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_100__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_101__Y.slice<2>().val() : value<1>{0u}))))))))))));
	// cells $procmux$689 $procmux$687 $procmux$685 $procmux$683 $procmux$681 $procmux$679 $procmux$677 $procmux$675 $procmux$673 $procmux$671 $procmux$669
	i_procmux_24_691__Y.next = (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_166__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_167__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_160__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_161__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_154__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_155__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_148__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_149__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_142__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_143__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_136__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_137__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_130__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_131__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_124__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_125__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_118__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_119__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_112__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_113__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_106__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_107__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_100__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_101__Y.slice<3>().val() : value<1>{0u}))))))))))));
	// cells $procmux$665 $procmux$663 $procmux$661 $procmux$659 $procmux$657 $procmux$655 $procmux$653 $procmux$651 $procmux$649 $procmux$647 $procmux$645
	i_procmux_24_667__Y.next = (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_168__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_169__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_162__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_163__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_156__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_157__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_150__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_151__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_144__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_145__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_138__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_139__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_132__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_133__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_126__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_127__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_120__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_121__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_114__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_115__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_108__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_109__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_102__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_103__Y.slice<0>().val() : value<1>{0u}))))))))))));
	// cells $procmux$641 $procmux$639 $procmux$637 $procmux$635 $procmux$633 $procmux$631 $procmux$629 $procmux$627 $procmux$625 $procmux$623 $procmux$621
	i_procmux_24_643__Y.next = (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_168__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_169__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_162__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_163__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_156__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_157__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_150__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_151__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_144__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_145__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_138__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_139__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_132__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_133__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_126__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_127__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_120__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_121__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_114__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_115__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_108__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_109__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_102__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_103__Y.slice<1>().val() : value<1>{0u}))))))))))));
	// cells $procmux$617 $procmux$615 $procmux$613 $procmux$611 $procmux$609 $procmux$607 $procmux$605 $procmux$603 $procmux$601 $procmux$599 $procmux$597
	i_procmux_24_619__Y.next = (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_168__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_169__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_162__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_163__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_156__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_157__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_150__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_151__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_144__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_145__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_138__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_139__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_132__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_133__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_126__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_127__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_120__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_121__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_114__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_115__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_108__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_109__Y.slice<2>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_102__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_103__Y.slice<2>().val() : value<1>{0u}))))))))))));
	// cells $procmux$593 $procmux$591 $procmux$589 $procmux$587 $procmux$585 $procmux$583 $procmux$581 $procmux$579 $procmux$577 $procmux$575 $procmux$573
	i_procmux_24_595__Y.next = (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_168__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_169__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_162__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_163__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_156__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_157__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_150__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_151__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_144__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_145__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_138__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_139__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_132__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_133__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_126__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_127__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_120__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_121__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_114__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_115__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_108__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_109__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_102__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_103__Y.slice<3>().val() : value<1>{0u}))))))))))));
	// cells $procmux$569 $procmux$567 $procmux$565 $procmux$563 $procmux$561 $procmux$559 $procmux$557 $procmux$555 $procmux$553 $procmux$551 $procmux$549
	i_procmux_24_571__Y.next = (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_170__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_171__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_164__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_165__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_158__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_159__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_152__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_153__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_146__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_147__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_140__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_141__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_134__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_135__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_128__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_129__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_122__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_123__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_116__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_117__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_110__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_111__Y.slice<0>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_104__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_105__Y.slice<0>().val() : value<1>{0u}))))))))))));
	// cells $procmux$545 $procmux$543 $procmux$541 $procmux$539 $procmux$537 $procmux$535 $procmux$533 $procmux$531 $procmux$529 $procmux$527 $procmux$525
	i_procmux_24_547__Y.next = (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_170__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_171__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_164__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_165__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_158__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_159__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_152__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_153__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_146__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_147__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_140__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_141__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_134__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_135__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_128__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_129__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_122__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_123__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_116__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_117__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_110__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_111__Y.slice<1>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_104__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_105__Y.slice<1>().val() : value<1>{0u}))))))))))));
	// cells $procmux$521 $procmux$519 $procmux$517 $procmux$515 $procmux$513 $procmux$511 $procmux$509 $procmux$507 $procmux$505 $procmux$503 $procmux$501
	i_procmux_24_523__Y.next = (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_170__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_171__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_164__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_165__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_158__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_159__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_152__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_153__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_146__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_147__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_140__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_141__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_134__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_135__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_128__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_129__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_122__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_123__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_116__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_117__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_110__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_111__Y.slice<3>().val() : (i_gt_24_alu_2f_bin2bcd_2e_v_3a_9_24_104__Y ? i_add_24_alu_2f_bin2bcd_2e_v_3a_10_24_105__Y.slice<3>().val() : value<1>{0u}))))))))))));
	// connection
	p_j = value<1>{0x1u};
	// connection
	p_i = value<1>{0u};
	// connection
	i_0_5c_bcd_5b_11_3a_0_5d_.slice<10>() = i_procmux_24_787__Y.curr;
	// connection
	i_0_5c_bcd_5b_11_3a_0_5d_.slice<0>() = i_procmux_24_763__Y.curr;
	// connection
	i_0_5c_bcd_5b_11_3a_0_5d_.slice<1>() = i_procmux_24_739__Y.curr;
	// connection
	i_0_5c_bcd_5b_11_3a_0_5d_.slice<2>() = i_procmux_24_715__Y.curr;
	// connection
	i_0_5c_bcd_5b_11_3a_0_5d_.slice<3>() = i_procmux_24_691__Y.curr;
	// connection
	i_0_5c_bcd_5b_11_3a_0_5d_.slice<4>() = i_procmux_24_667__Y.curr;
	// connection
	i_0_5c_bcd_5b_11_3a_0_5d_.slice<5>() = i_procmux_24_643__Y.curr;
	// connection
	i_0_5c_bcd_5b_11_3a_0_5d_.slice<6>() = i_procmux_24_619__Y.curr;
	// connection
	i_0_5c_bcd_5b_11_3a_0_5d_.slice<7>() = i_procmux_24_595__Y.curr;
	// connection
	i_0_5c_bcd_5b_11_3a_0_5d_.slice<8>() = i_procmux_24_571__Y.curr;
	// connection
	i_0_5c_bcd_5b_11_3a_0_5d_.slice<9>() = i_procmux_24_547__Y.curr;
	// connection
	i_0_5c_bcd_5b_11_3a_0_5d_.slice<11>() = i_procmux_24_523__Y.curr;
	// connection
	i_0_5c_j_5b_0_3a_0_5d_ = value<1>{0x1u};
	// connection
	i_0_5c_i_5b_0_3a_0_5d_ = value<1>{0u};
	return converged;
}

bool p_bin2bcd::commit() {
	bool changed = false;
	changed |= i_procmux_24_787__Y.commit();
	changed |= i_procmux_24_763__Y.commit();
	changed |= i_procmux_24_739__Y.commit();
	changed |= i_procmux_24_715__Y.commit();
	changed |= i_procmux_24_691__Y.commit();
	changed |= i_procmux_24_667__Y.commit();
	changed |= i_procmux_24_643__Y.commit();
	changed |= i_procmux_24_619__Y.commit();
	changed |= i_procmux_24_595__Y.commit();
	changed |= i_procmux_24_571__Y.commit();
	changed |= i_procmux_24_547__Y.commit();
	changed |= i_procmux_24_523__Y.commit();
	changed |= p_bcd.commit();
	return changed;
}

void p_bin2bcd::debug_info(debug_items &items, std::string path) {
	assert(path.empty() || path[path.size() - 1] == ' ');
	static const value<1> const_p_j = value<1>{0x1u};
	items.add(path + "j", debug_item(const_p_j, 0));
	static const value<1> const_p_i = value<1>{0u};
	items.add(path + "i", debug_item(const_p_i, 0));
	items.add(path + "bcd", debug_item(p_bcd, 0));
	items.add(path + "bin", debug_item(p_bin, 0));
}

// \cells_not_processed: 1
// \src: alu/notop.v:1.1-12.10
struct p_notop : public module {
	// \src: alu/notop.v:3.28-3.31
	/*output*/ wire<11> p_out;
	// \src: alu/notop.v:2.23-2.26
	/*input*/ value<11> p_acc;

	bool eval() override;
	bool commit() override;
	void debug_info(debug_items &items, std::string path = "") override;
}; // struct p_notop

bool p_notop::eval() {
	bool converged = false;
	value<11> i_procmux_24_199__Y;
	// \src: alu/notop.v:5.3-11.6
	value<11> i_0_5c_out_5b_10_3a_0_5d_;
	// cells $eq$alu/notop.v:7$184
	i_procmux_24_199__Y = (eq_ss<1>(p_acc, value<32>{0u}) ? value<11>{0x64u} : value<11>{0u});
	// connection
	p_out.next = i_procmux_24_199__Y;
	// connection
	i_0_5c_out_5b_10_3a_0_5d_ = i_procmux_24_199__Y;
	return converged;
}

bool p_notop::commit() {
	bool changed = false;
	changed |= p_out.commit();
	return changed;
}

void p_notop::debug_info(debug_items &items, std::string path) {
	assert(path.empty() || path[path.size() - 1] == ' ');
	items.add(path + "out", debug_item(p_out, 0));
	items.add(path + "acc", debug_item(p_acc, 0));
}

} // namespace cxxrtl_design

