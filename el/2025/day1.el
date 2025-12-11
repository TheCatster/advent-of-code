;;; day1.el -*- lexical-binding: t; -*-

;;; Commentary:
;; Advent of Code 2025 Day 1 Solution 
;; We read in the input file and parse it into a list of lines.
;; We then iterate over the list of lines and parse each line into a direction and a value.
;; We then move the dial in the direction of the value and count the number of times the dial lands exactly on 0.

;;; Code:

(defun day1-read-input (file)
  "Read lines from FILE."
  (with-temp-buffer
    (insert-file-contents file)
    (split-string (buffer-string) "\n" t)))

(defun part-one ()
  "Solve Part 1: Count times the dial lands exactly on 0."
  (let ((lines (day1-read-input "input/2025/1"))
        (pos 50)
        (count 0))
    (dolist (line lines)
      (when (> (length line) 0)
        (let ((dir (aref line 0))
              (val (string-to-number (substring line 1))))
          (cond
           ((= dir ?L)
            (setq pos (- pos val)))
           ((= dir ?R)
            (setq pos (+ pos val))))
          
          ;; Normalize position to 0-99
          (setq pos (mod pos 100))
          
          (when (= pos 0)
            (setq count (1+ count))))))
    count))

(defun part-two ()
  "Solve Part 2: Count every time the dial touches 0."
  (let ((lines (day1-read-input "input/2025/1"))
        (pos 50)
        (count 0))
    (dolist (line lines)
      (when (> (length line) 0)
        (let ((dir (aref line 0))
              (val (string-to-number (substring line 1))))
          (dotimes (_ val)
            (cond
             ((= dir ?L)
              (setq pos (1- pos)))
             ((= dir ?R)
              (setq pos (1+ pos))))
            
            ;; Normalize position to 0-99
            (setq pos (mod pos 100))
            
            (when (= pos 0)
              (setq count (1+ count)))))))
    count))

(provide 'day1)
;;; day1.el ends here
