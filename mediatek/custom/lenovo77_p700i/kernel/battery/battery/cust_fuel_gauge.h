#include <mach/mt_typedefs.h>

#define FGAUGE_VOLTAGE_FACTOR           2.44 // mV
#define FGAUGE_CURRENT_FACTOR           6.25 // uV/Rsns
#define FGAUGE_CURRENT_OFFSET_FACTOR    1.56 // uV/Rsns
#define FGAUGE_CAR_FACTOR               6.25 // uV/Rsns
#define FGAUGE_RSNS_FACTOR              0.02 // Ohm

#define COMPASATE_OCV                   40 // mV for phone

#define BATTERY_VOLTAGE_MINIMUM         3400
#define BATTERY_VOLTAGE_MAXIMUM         4200

#define BATTERY_CAPACITY_MAXIMUM        2500

#define TEMPERATURE_T0                  110
#define TEMPERATURE_T1                  0
#define TEMPERATURE_T2                  25
#define TEMPERATURE_T3                  50
#define TEMPERATURE_T                   255 // This should be fixed, never change the value

#define BATT_CAPACITY                   2500

#define ENABLE_SW_COULOMB_COUNTER       0 // 1 is enable, 0 is disable
//#define ENABLE_SW_COULOMB_COUNTER       1 // 1 is enable, 0 is disable

#define FG_CURRENT_OFFSET_DISCHARGING 	0
#define FG_RESISTANCE		 	20
#define FG_METER_RESISTANCE 		0

//#define MAX_BOOTING_TIME_FGCURRENT	5*6 // 5 seconds, 6 points = 1s
#define MAX_BOOTING_TIME_FGCURRENT	1*10 // 10s

#if defined(CONFIG_POWER_EXT)
#define OCV_BOARD_COMPESATE	72 //mV 
#define R_FG_BOARD_BASE		1000
#define R_FG_BOARD_SLOPE	1000 //slope
#else
#define OCV_BOARD_COMPESATE	0 //mV 
#define R_FG_BOARD_BASE		1000
#define R_FG_BOARD_SLOPE	1000 //slope
#endif

// Battery capacity for P700i
#define Q_MAX_POS_50		2557
#define Q_MAX_POS_25		2533
#define Q_MAX_POS_0		2531
#define Q_MAX_NEG_10		2547
#define Q_MAX_POS_50_H_CURRENT	2533
#define Q_MAX_POS_25_H_CURRENT	2509
#define Q_MAX_POS_0_H_CURRENT	2463
#define Q_MAX_NEG_10_H_CURRENT	2300

#define R_FG_VALUE 		20 // mOhm, base is 20
#define CURRENT_DETECT_R_FG	100  //10mA

#define OSR_SELECT_7		0

#define CAR_TUNE_VALUE		101 //1.01

/////////////////////////////////////////////////////////////////////
// <DOD, Battery_Voltage> Table
/////////////////////////////////////////////////////////////////////
typedef struct _BATTERY_PROFILE_STRUC
{
    kal_int32 percentage;
    kal_int32 voltage;
} BATTERY_PROFILE_STRUC, *BATTERY_PROFILE_STRUC_P;

typedef enum
{
    T1_0C,
    T2_25C,
    T3_50C
} PROFILE_TEMPERATURE;

// T0 -10C
BATTERY_PROFILE_STRUC battery_profile_t0[] =
{
	{	0	,	4185	},
	{	1	,	4166	},
	{	3	,	4151	},
	{	4	,	4136	},
	{	5	,	4123	},
	{	7	,	4109	},
	{	8	,	4097	},
	{	10	,	4084	},
	{	11	,	4073	},
	{	12	,	4061	},
	{	14	,	4047	},
	{	15	,	4031	},
	{	16	,	4015	},
	{	18	,	4000	},
	{	19	,	3988	},
	{	20	,	3978	},
	{	22	,	3967	},
	{	23	,	3958	},
	{	24	,	3948	},
	{	26	,	3939	},
	{	27	,	3930	},
	{	29	,	3921	},
	{	30	,	3911	},
	{	31	,	3902	},
	{	33	,	3894	},
	{	34	,	3885	},
	{	35	,	3878	},
	{	37	,	3870	},
	{	38	,	3862	},
	{	39	,	3855	},
	{	41	,	3848	},
	{	42	,	3842	},
	{	43	,	3836	},
	{	45	,	3829	},
	{	46	,	3824	},
	{	48	,	3818	},
	{	49	,	3813	},
	{	50	,	3807	},
	{	52	,	3803	},
	{	53	,	3798	},
	{	54	,	3794	},
	{	56	,	3789	},
	{	57	,	3785	},
	{	58	,	3782	},
	{	60	,	3777	},
	{	61	,	3774	},
	{	63	,	3771	},
	{	64	,	3768	},
	{	65	,	3765	},
	{	67	,	3762	},
	{	68	,	3760	},
	{	69	,	3757	},
	{	71	,	3755	},
	{	72	,	3751	},
	{	73	,	3748	},
	{	75	,	3745	},
	{	76	,	3741	},
	{	77	,	3737	},
	{	79	,	3732	},
	{	80	,	3728	},
	{	82	,	3724	},
	{	83	,	3720	},
	{	84	,	3717	},
	{	86	,	3712	},
	{	87	,	3708	},
	{	88	,	3701	},
	{	90	,	3693	},
	{	91	,	3680	},
	{	92	,	3664	},
	{	94	,	3642	},
	{	95	,	3615	},
	{	96	,	3579	},
	{	98	,	3533	},
	{	98	,	3514	},
	{	99	,	3498	},
	{	99	,	3484	},
	{	99	,	3472	},
	{	99	,	3486	},
	{	100	,	3467	},
	{	100	,	3455	},
	{	100	,	3455	}
};      
        
// T1 0C
BATTERY_PROFILE_STRUC battery_profile_t1[] =
{
	{	0	,	4179	},
	{	1	,	4163	},
	{	3	,	4148	},
	{	4	,	4135	},
	{	5	,	4121	},
	{	7	,	4108	},
	{	8	,	4095	},
	{	10	,	4083	},
	{	11	,	4072	},
	{	12	,	4061	},
	{	14	,	4048	},
	{	15	,	4035	},
	{	16	,	4021	},
	{	18	,	4009	},
	{	19	,	3998	},
	{	21	,	3988	},
	{	22	,	3978	},
	{	23	,	3969	},
	{	25	,	3959	},
	{	26	,	3949	},
	{	27	,	3939	},
	{	29	,	3929	},
	{	30	,	3919	},
	{	31	,	3909	},
	{	33	,	3900	},
	{	34	,	3891	},
	{	36	,	3881	},
	{	37	,	3873	},
	{	38	,	3865	},
	{	40	,	3857	},
	{	41	,	3849	},
	{	42	,	3843	},
	{	44	,	3836	},
	{	45	,	3831	},
	{	47	,	3825	},
	{	48	,	3820	},
	{	49	,	3815	},
	{	51	,	3810	},
	{	52	,	3806	},
	{	53	,	3802	},
	{	55	,	3798	},
	{	56	,	3794	},
	{	57	,	3790	},
	{	59	,	3787	},
	{	60	,	3784	},
	{	62	,	3781	},
	{	63	,	3778	},
	{	64	,	3776	},
	{	66	,	3773	},
	{	67	,	3770	},
	{	68	,	3768	},
	{	70	,	3766	},
	{	71	,	3763	},
	{	72	,	3761	},
	{	74	,	3758	},
	{	75	,	3754	},
	{	77	,	3751	},
	{	78	,	3747	},
	{	79	,	3742	},
	{	81	,	3738	},
	{	82	,	3733	},
	{	83	,	3728	},
	{	85	,	3722	},
	{	86	,	3715	},
	{	88	,	3707	},
	{	89	,	3701	},
	{	90	,	3697	},
	{	92	,	3693	},
	{	93	,	3686	},
	{	94	,	3673	},
	{	96	,	3643	},
	{	97	,	3594	},
	{	98	,	3524	},
	{	100	,	3424	},
	{	101	,	3322	},
	{	101	,	3279	},
	{	101	,	3254	},
	{	101	,	3240	},
	{	101	,	3230	},
	{	102	,	3222	},
	{	102	,	3222	}
};

// T2 25C
BATTERY_PROFILE_STRUC battery_profile_t2[] =
{
	{	0	,	4175	},
	{	1	,	4157	},
	{	3	,	4142	},
	{	4	,	4127	},
	{	5	,	4114	},
	{	7	,	4101	},
	{	8	,	4088	},
	{	10	,	4076	},
	{	11	,	4064	},
	{	12	,	4053	},
	{	14	,	4041	},
	{	15	,	4029	},
	{	16	,	4019	},
	{	18	,	4008	},
	{	19	,	3998	},
	{	20	,	3988	},
	{	22	,	3979	},
	{	23	,	3969	},
	{	25	,	3960	},
	{	26	,	3952	},
	{	27	,	3943	},
	{	29	,	3935	},
	{	30	,	3927	},
	{	31	,	3919	},
	{	33	,	3911	},
	{	34	,	3902	},
	{	36	,	3893	},
	{	37	,	3883	},
	{	38	,	3871	},
	{	40	,	3860	},
	{	41	,	3850	},
	{	42	,	3842	},
	{	44	,	3834	},
	{	45	,	3828	},
	{	46	,	3823	},
	{	48	,	3817	},
	{	49	,	3813	},
	{	51	,	3808	},
	{	52	,	3804	},
	{	53	,	3799	},
	{	55	,	3796	},
	{	56	,	3792	},
	{	57	,	3789	},
	{	59	,	3786	},
	{	60	,	3784	},
	{	61	,	3781	},
	{	63	,	3778	},
	{	64	,	3776	},
	{	66	,	3774	},
	{	67	,	3772	},
	{	68	,	3770	},
	{	70	,	3766	},
	{	71	,	3761	},
	{	72	,	3756	},
	{	74	,	3752	},
	{	75	,	3746	},
	{	77	,	3742	},
	{	78	,	3738	},
	{	79	,	3734	},
	{	81	,	3730	},
	{	82	,	3724	},
	{	83	,	3718	},
	{	85	,	3712	},
	{	86	,	3706	},
	{	87	,	3699	},
	{	89	,	3689	},
	{	90	,	3683	},
	{	92	,	3680	},
	{	93	,	3677	},
	{	94	,	3670	},
	{	96	,	3645	},
	{	97	,	3595	},
	{	98	,	3528	},
	{	100	,	3432	},
	{	101	,	3271	},
	{	102	,	3122	},
	{	102	,	3090	},
	{	102	,	3079	},
	{	102	,	3073	},
	{	102	,	3070	},
	{	102	,	3070	}
}; 

// T3 50C
BATTERY_PROFILE_STRUC battery_profile_t3[] =
{
	{	0	,	4188	}	,
	{	1	,	4172	}	,
	{	3	,	4156	}	,
	{	4	,	4141	}	,
	{	6	,	4126	}	,
	{	7	,	4113	}	,
	{	9	,	4099	}	,
	{	10	,	4085	}	,
	{	11	,	4073	}	,
	{	13	,	4060	}	,
	{	14	,	4048	}	,
	{	16	,	4036	}	,
	{	17	,	4024	}	,
	{	19	,	4012	}	,
	{	20	,	4001	}	,
	{	21	,	3990	}	,
	{	23	,	3980	}	,
	{	24	,	3969	}	,
	{	26	,	3959	}	,
	{	27	,	3949	}	,
	{	29	,	3939	}	,
	{	30	,	3930	}	,
	{	31	,	3922	}	,
	{	33	,	3913	}	,
	{	34	,	3903	}	,
	{	36	,	3895	}	,
	{	37	,	3886	}	,
	{	39	,	3874	}	,
	{	40	,	3860	}	,
	{	41	,	3849	}	,
	{	43	,	3839	}	,
	{	44	,	3832	}	,
	{	46	,	3825	}	,
	{	47	,	3819	}	,
	{	49	,	3813	}	,
	{	50	,	3808	}	,
	{	52	,	3803	}	,
	{	53	,	3799	}	,
	{	54	,	3796	}	,
	{	56	,	3791	}	,
	{	57	,	3788	}	,
	{	59	,	3785	}	,
	{	60	,	3782	}	,
	{	62	,	3778	}	,
	{	63	,	3776	}	,
	{	64	,	3773	}	,
	{	66	,	3770	}	,
	{	67	,	3768	}	,
	{	69	,	3764	}	,
	{	70	,	3756	}	,
	{	71	,	3746	}	,
	{	73	,	3741	}	,
	{	74	,	3735	}	,
	{	76	,	3729	}	,
	{	77	,	3725	}	,
	{	79	,	3720	}	,
	{	80	,	3717	}	,
	{	81	,	3712	}	,
	{	83	,	3705	}	,
	{	84	,	3698	}	,
	{	86	,	3692	}	,
	{	87	,	3685	}	,
	{	89	,	3674	}	,
	{	90	,	3669	}	,
	{	91	,	3667	}	,
	{	93	,	3663	}	,
	{	94	,	3657	}	,
	{	96	,	3634	}	,
	{	97	,	3585	}	,
	{	99	,	3515	}	,
	{	100	,	3411	}	,
	{	101	,	3273	}	,
	{	101	,	3260	}	,
	{	101	,	3260	}	,
	{	101	,	3260	}	,
	{	101	,	3260	}	,
	{	101	,	3260	}	,
	{	101	,	3260	}	,
	{	101	,	3260	}	,
	{	101	,	3260	}	,
	{	101	,	3260	}	,
};              

// battery profile for actual temperature. The size should be the same as T1, T2 and T3
BATTERY_PROFILE_STRUC battery_profile_temperature[] =
{
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
	  {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
	  {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0}
};    

/////////////////////////////////////////////////////////////////////
// <Rbat, Battery_Voltage> Table
/////////////////////////////////////////////////////////////////////
typedef struct _R_PROFILE_STRUC
{
    kal_int32 resistance; // Ohm
    kal_int32 voltage;
} R_PROFILE_STRUC, *R_PROFILE_STRUC_P;

// T0 -10C
R_PROFILE_STRUC r_profile_t0[] =
{
	{	358	,	4193	},
	{	513	,	4174	},
	{	520	,	4157	},
	{	523	,	4140	},
	{	528	,	4124	},
	{	533	,	4109	},
	{	530	,	4093	},
	{	538	,	4081	},
	{	540	,	4068	},
	{	540	,	4051	},
	{	543	,	4031	},
	{	538	,	4010	},
	{	538	,	3993	},
	{	538	,	3980	},
	{	538	,	3968	},
	{	533	,	3956	},
	{	530	,	3945	},
	{	523	,	3933	},
	{	518	,	3921	},
	{	515	,	3909	},
	{	513	,	3898	},
	{	513	,	3887	},
	{	510	,	3877	},
	{	510	,	3867	},
	{	508	,	3858	},
	{	510	,	3850	},
	{	510	,	3842	},
	{	510	,	3834	},
	{	510	,	3827	},
	{	515	,	3821	},
	{	518	,	3815	},
	{	520	,	3809	},
	{	523	,	3804	},
	{	525	,	3798	},
	{	528	,	3794	},
	{	530	,	3789	},
	{	535	,	3785	},
	{	535	,	3781	},
	{	538	,	3777	},
	{	540	,	3774	},
	{	540	,	3771	},
	{	545	,	3769	},
	{	548	,	3766	},
	{	545	,	3763	},
	{	548	,	3759	},
	{	548	,	3755	},
	{	550	,	3751	},
	{	555	,	3747	},
	{	555	,	3742	},
	{	558	,	3736	},
	{	563	,	3722	},
	{	573	,	3715	},
	{	585	,	3709	},
	{	610	,	3704	},
	{	643	,	3698	},
	{	698	,	3690	},
	{	775	,	3673	},
	{	898	,	3639	},
	{	1180	,	3585	},
	{	1353	,	3540	},
	{	1280	,	3512	},
	{	1228	,	3489	},
	{	1180	,	3469	},
	{	1143	,	3451	},
	{	1105	,	3437	},
	{	1070	,	3424	},
	{	1050	,	3412	},
	{	1023	,	3402	},
	{	990	,	3392	},
	{	965	,	3384	},
	{	943	,	3376	},
	{	933	,	3369	},
	{	918	,	3363	},
	{	905	,	3397	},
	{	900	,	3350	},
	{	878	,	3345	},
	{	855	,	3340	},
	{	855	,	3337	},
	{	840	,	3332	},
	{	860	,	3332	},
};

// T1 0C
R_PROFILE_STRUC r_profile_t1[] =
{
	{	260	,	4198	},
	{	320	,	4179	},
	{	328	,	4162	},
	{	330	,	4145	},
	{	335	,	4129	},
	{	340	,	4114	},
	{	343	,	4098	},
	{	345	,	4084	},
	{	353	,	4072	},
	{	355	,	4058	},
	{	358	,	4040	},
	{	358	,	4021	},
	{	360	,	4005	},
	{	360	,	3992	},
	{	363	,	3981	},
	{	363	,	3970	},
	{	360	,	3958	},
	{	360	,	3947	},
	{	355	,	3934	},
	{	345	,	3920	},
	{	343	,	3908	},
	{	340	,	3896	},
	{	333	,	3884	},
	{	328	,	3873	},
	{	325	,	3863	},
	{	325	,	3854	},
	{	325	,	3846	},
	{	325	,	3838	},
	{	323	,	3830	},
	{	325	,	3824	},
	{	328	,	3818	},
	{	328	,	3812	},
	{	333	,	3807	},
	{	333	,	3802	},
	{	333	,	3797	},
	{	335	,	3793	},
	{	340	,	3789	},
	{	338	,	3785	},
	{	343	,	3782	},
	{	343	,	3779	},
	{	343	,	3776	},
	{	343	,	3773	},
	{	348	,	3771	},
	{	345	,	3768	},
	{	343	,	3764	},
	{	348	,	3762	},
	{	345	,	3757	},
	{	348	,	3753	},
	{	350	,	3749	},
	{	350	,	3743	},
	{	350	,	3736	},
	{	353	,	3730	},
	{	353	,	3722	},
	{	353	,	3713	},
	{	353	,	3704	},
	{	360	,	3698	},
	{	380	,	3694	},
	{	410	,	3688	},
	{	445	,	3673	},
	{	465	,	3627	},
	{	545	,	3549	},
	{	848	,	3425	},
	{	880	,	3350	},
	{	773	,	3305	},
	{	703	,	3275	},
	{	648	,	3253	},
	{	608	,	3238	},
	{	578	,	3224	},
	{	555	,	3215	},
	{	525	,	3205	},
	{	510	,	3199	},
	{	488	,	3194	},
	{	488	,	3188	},
	{	468	,	3183	},
	{	460	,	3180	},
	{	463	,	3174	},
	{	450	,	3170	},
	{	453	,	3166	},
	{	420	,	3164	},
	{	423	,	3164	},
	{	428	,	3164	},
}; 

// T2 25C
R_PROFILE_STRUC r_profile_t2[] =
{
	{	158	,	4184	}	,
	{	160	,	4166	}	,
	{	163	,	4150	}	,
	{	165	,	4136	}	,
	{	168	,	4122	}	,
	{	170	,	4109	}	,
	{	170	,	4095	}	,
	{	173	,	4082	}	,
	{	173	,	4070	}	,
	{	175	,	4058	}	,
	{	178	,	4046	}	,
	{	178	,	4033	}	,
	{	180	,	4021	}	,
	{	183	,	4009	}	,
	{	185	,	3999	}	,
	{	185	,	3988	}	,
	{	190	,	3979	}	,
	{	193	,	3969	}	,
	{	193	,	3959	}	,
	{	195	,	3950	}	,
	{	198	,	3941	}	,
	{	198	,	3932	}	,
	{	195	,	3923	}	,
	{	195	,	3913	}	,
	{	198	,	3904	}	,
	{	195	,	3893	}	,
	{	198	,	3880	}	,
	{	175	,	3867	}	,
	{	168	,	3855	}	,
	{	160	,	3846	}	,
	{	158	,	3838	}	,
	{	155	,	3831	}	,
	{	153	,	3824	}	,
	{	155	,	3819	}	,
	{	158	,	3814	}	,
	{	160	,	3810	}	,
	{	158	,	3805	}	,
	{	160	,	3801	}	,
	{	160	,	3797	}	,
	{	158	,	3793	}	,
	{	158	,	3789	}	,
	{	160	,	3786	}	,
	{	160	,	3783	}	,
	{	163	,	3780	}	,
	{	165	,	3778	}	,
	{	163	,	3775	}	,
	{	165	,	3773	}	,
	{	163	,	3770	}	,
	{	163	,	3767	}	,
	{	155	,	3761	}	,
	{	155	,	3757	}	,
	{	155	,	3752	}	,
	{	153	,	3746	}	,
	{	153	,	3741	}	,
	{	155	,	3737	}	,
	{	155	,	3733	}	,
	{	158	,	3729	}	,
	{	155	,	3722	}	,
	{	153	,	3715	}	,
	{	158	,	3709	}	,
	{	158	,	3702	}	,
	{	158	,	3693	}	,
	{	153	,	3684	}	,
	{	155	,	3681	}	,
	{	163	,	3678	}	,
	{	170	,	3674	}	,
	{	155	,	3663	}	,
	{	173	,	3625	}	,
	{	180	,	3564	}	,
	{	193	,	3478	}	,
	{	223	,	3343	}	,
	{	208	,	3281	}	,
	{	165	,	3266	}	,
	{	170	,	3266	}	,
	{	170	,	3266	}	,
	{	170	,	3266	}	,
	{	170	,	3266	}	,
	{	170	,	3266	}	,
	{	170	,	3266	}	,
	{	170	,	3266	}	,
	{	170	,	3266	}	,
}; 

// T3 50C
R_PROFILE_STRUC r_profile_t3[] =
{
	{	138	,	4188	},
	{	143	,	4172	},
	{	143	,	4156	},
	{	143	,	4141	},
	{	143	,	4126	},
	{	145	,	4113	},
	{	145	,	4099	},
	{	145	,	4085	},
	{	145	,	4073	},
	{	148	,	4060	},
	{	148	,	4048	},
	{	148	,	4036	},
	{	150	,	4024	},
	{	150	,	4012	},
	{	150	,	4001	},
	{	150	,	3990	},
	{	153	,	3980	},
	{	153	,	3969	},
	{	153	,	3959	},
	{	155	,	3949	},
	{	155	,	3939	},
	{	158	,	3930	},
	{	163	,	3922	},
	{	165	,	3913	},
	{	165	,	3903	},
	{	168	,	3895	},
	{	168	,	3886	},
	{	163	,	3874	},
	{	155	,	3860	},
	{	148	,	3849	},
	{	145	,	3839	},
	{	148	,	3832	},
	{	148	,	3825	},
	{	145	,	3819	},
	{	145	,	3813	},
	{	145	,	3808	},
	{	145	,	3803	},
	{	148	,	3799	},
	{	150	,	3796	},
	{	145	,	3791	},
	{	148	,	3788	},
	{	150	,	3785	},
	{	153	,	3782	},
	{	150	,	3778	},
	{	155	,	3776	},
	{	155	,	3773	},
	{	155	,	3770	},
	{	158	,	3768	},
	{	155	,	3764	},
	{	148	,	3756	},
	{	140	,	3746	},
	{	143	,	3741	},
	{	143	,	3735	},
	{	143	,	3729	},
	{	143	,	3725	},
	{	143	,	3720	},
	{	148	,	3717	},
	{	145	,	3712	},
	{	145	,	3705	},
	{	145	,	3698	},
	{	145	,	3692	},
	{	148	,	3685	},
	{	143	,	3674	},
	{	145	,	3669	},
	{	150	,	3667	},
	{	153	,	3663	},
	{	158	,	3657	},
	{	153	,	3634	},
	{	158	,	3585	},
	{	160	,	3515	},
	{	165	,	3411	},
	{	183	,	3273	},
	{	150	,	3260	},
	{	153	,	3260	},
	{	153	,	3260	},
	{	153	,	3260	},
	{	153	,	3260	},
	{	153	,	3260	},
	{	153	,	3260	},
	{	153	,	3260	},
	{	153	,	3260	},
};

// r-table profile for actual temperature. The size should be the same as T1, T2 and T3
R_PROFILE_STRUC r_profile_temperature[] =
{
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
	  {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
	  {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0}
};    


int fgauge_get_saddles(void);
BATTERY_PROFILE_STRUC_P fgauge_get_profile(kal_uint32 temperature);

int fgauge_get_saddles_r_table(void);
R_PROFILE_STRUC_P fgauge_get_profile_r_table(kal_uint32 temperature);
