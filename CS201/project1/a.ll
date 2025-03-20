; ModuleID = 'a.ll'
source_filename = "test.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@.str = private unnamed_addr constant [13 x i8] c"Hello world\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  store i32 10, ptr %2, align 4
  call void @test(i32 noundef 10, double noundef 1.010000e+01, i8 noundef signext 97)
  %4 = load i32, ptr %2, align 4
  %5 = icmp eq i32 %4, 10
  br i1 %5, label %6, label %9

6:                                                ; preds = %0
  %7 = load i32, ptr %2, align 4
  %8 = mul nsw i32 %7, 10
  store i32 %8, ptr %3, align 4
  br label %19

9:                                                ; preds = %0
  %10 = load i32, ptr %2, align 4
  %11 = icmp eq i32 %10, 20
  br i1 %11, label %12, label %15

12:                                               ; preds = %9
  %13 = load i32, ptr %2, align 4
  %14 = mul nsw i32 %13, 20
  store i32 %14, ptr %3, align 4
  br label %18

15:                                               ; preds = %9
  %16 = load i32, ptr %2, align 4
  %17 = mul nsw i32 %16, 30
  store i32 %17, ptr %3, align 4
  br label %18

18:                                               ; preds = %15, %12
  br label %19

19:                                               ; preds = %18, %6
  %20 = call i32 (ptr, ...) @printf(ptr noundef @.str)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @test(i32 noundef %0, double noundef %1, i8 noundef signext %2) #0 {
  %4 = alloca i32, align 4
  %5 = alloca double, align 8
  %6 = alloca i8, align 1
  %7 = alloca double, align 8
  %8 = alloca i8, align 1
  store i32 %0, ptr %4, align 4
  store double %1, ptr %5, align 8
  store i8 %2, ptr %6, align 1
  %9 = load i32, ptr %4, align 4
  %10 = sitofp i32 %9 to double
  %11 = load double, ptr %5, align 8
  %12 = fmul double %10, %11
  store double %12, ptr %7, align 8
  %13 = load i8, ptr %6, align 1
  store i8 %13, ptr %8, align 1
  ret void
}

declare i32 @printf(ptr noundef, ...) #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 17.0.6 (++20231208085846+6009708b4367-1~exp1~20231208085949.74)"}
