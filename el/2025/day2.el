;;; day2.el -*- lexical-binding: t; -*-

;;; Commentary:
;; Advent of Code 2025 Day 2 Solution
;; An ID is invalid if its decimal representation is a sequence of digits repeated exactly twice.
;; e.g. "123123" is invalid, "1212" is invalid.

;;; Code:

(require 'cl-lib)

(defun day2-is-invalid-id (n)
  "Check if integer N is an 'invalid' ID.
An ID is invalid if its string representation consists of two identical halves."
  (let* ((s (number-to-string n))
         (len (length s)))
    (when (cl-evenp len)
      (let ((half (/ len 2)))
        (string= (substring s 0 half)
                 (substring s half))))))

(defun day2-read-input (file)
  "Read content from FILE."
  (with-temp-buffer
    (insert-file-contents file)
    (string-trim (buffer-string))))

(defun part-one ()
  "Solve Part 1: Sum all invalid IDs within the ranges."
  (let ((input (day2-read-input "input/2025/2"))
        (total-sum 0))
    (let ((ranges (split-string input ",")))
      (dolist (range ranges)
        (let* ((parts (split-string range "-"))
               (start (string-to-number (car parts)))
               (end (string-to-number (cadr parts))))
          (cl-loop for n from start to end
                   do (when (day2-is-invalid-id n)
                        (setq total-sum (+ total-sum n)))))))
    total-sum))

(defun part-two ()
  "Placeholder for Part 2."
  nil)

(provide 'day2)
;;; day2.el ends here

